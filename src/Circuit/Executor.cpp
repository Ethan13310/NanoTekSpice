/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Executor.cpp
*/

#include <iostream>
#include <memory>
#include <string>

#include "Circuit.hpp"
#include "Exceptions.hpp"
#include "Parser.hpp"
#include "Utils.hpp"

nts::Executor::Executor(Tree const &tree)
{
	for (auto const &node : tree.get()) {
		if (node.type == Tree::Node::Type::Component) {
			createComponent(node);
		}
		else if (node.type == Tree::Node::Type::Link) {
			createLink(node);
		}
	}
}

void nts::Executor::display() const
{
	for (auto const &output : m_outputs) {
		output.second.lock()->display(output.first);
	}
}

void nts::Executor::simulate()
{
	resetComputeState();

	for (auto const &output : m_outputs) {
		output.second.lock()->compute();
	}
}

void nts::Executor::dump() const
{
	std::size_t i{ 0 };

	for (auto const &component : m_components) {
		if (i != 0) {
			std::cout << std::endl;
		}
		std::cout << component.first << ": ";
		component.second->dump();
		++i;
	}
}

void nts::Executor::reverseClocks()
{
	for (auto &clock : m_clocks) {
		clock.second.lock()->reverse();
	}
}

void nts::Executor::updateInput(InputValue const &input)
{
	for (auto &it : m_inputs) {
		if (it.first == input.name) {
			it.second.lock()->setValue(input.value);
			return;
		}
	}
	throw InputErrorException{ "'" + input.name + "' does not exist." };
}

void nts::Executor::resetComputeState()
{
	for (auto const &component : m_components) {
		component.second->compute(0);
	}
}

void nts::Executor::createComponent(Tree::Node const &node)
{	
	std::map<std::string, CreateFunc> const factories{
		{ "input", &Executor::createInput },
		{ "output", &Executor::createOutput },
		{ "true", &Executor::createTrue },
		{ "false", &Executor::createFalse },
		{ "clock", &Executor::createClock },
		{ "terminal", &Executor::createTerminal }
	};

	Chipset const chipset{ node.name + "(" + node.value + ")" };

	auto const type{ chipset.type() };

	if (m_components.find(chipset.name()) != m_components.end()) {
		throw ParseErrorException{ "Component '" + chipset.name() + "' already exists." };
	}

	auto const it{ factories.find(type) };

	if (it != factories.end()) {
		it->second(*this, chipset);
	}
	else {
		auto component{ m_factory.createComponent(type, chipset.value()) };
		m_components[chipset.name()] = std::move(component);
	}
}

void nts::Executor::createInput(Chipset const &chipset)
{
	std::shared_ptr<Input> input{ std::move(m_factory.createInput(chipset.value())) };

	m_components[chipset.name()] = input;
	m_inputs[chipset.name()] = input;
}

void nts::Executor::createOutput(Chipset const &chipset)
{
	std::shared_ptr<Output> output{ std::move(m_factory.createOutput()) };
	
	m_components[chipset.name()] = output;
	m_outputs[chipset.name()] = output;
}

void nts::Executor::createTrue(Chipset const &chipset)
{
	std::shared_ptr<True> inputTrue{ std::move(m_factory.createTrue()) };
	
	m_components[chipset.name()] = inputTrue;
	m_inputs[chipset.name()] = inputTrue;
}

void nts::Executor::createFalse(Chipset const &chipset)
{
	std::shared_ptr<False> inputFalse{ std::move(m_factory.createFalse()) };
	
	m_components[chipset.name()] = inputFalse;
	m_inputs[chipset.name()] = inputFalse;
}

void nts::Executor::createClock(Chipset const &chipset)
{
	std::shared_ptr<Clock> clock{ std::move(m_factory.createClock(chipset.value())) };
	
	m_components[chipset.name()] = clock;
	m_clocks[chipset.name()] = clock;
	m_inputs[chipset.name()] = clock;
}

void nts::Executor::createTerminal(Chipset const &chipset)
{
	std::shared_ptr<Terminal> output{ std::move(m_factory.createTerminal()) };

	m_components[chipset.name()] = output;
	m_outputs[chipset.name()] = output;
}

void nts::Executor::createLink(Tree::Node const &node)
{
	Link const link{ node.name };

	auto const firstLink{ link.first() };
	auto const firstComp{ m_components.find(firstLink.name) };

	if (firstComp  == m_components.end()) {
		throw UnknownComponentException{ firstLink.name };
	}

	auto const secondLink{ link.second() };
	auto const secondComp{ m_components.find(secondLink.name) };

	if (secondComp == m_components.end()) {
		throw UnknownComponentException{ secondLink.name };
	}

	firstComp->second->setLink(firstLink.pin, *secondComp->second, secondLink.pin);
}
