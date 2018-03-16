/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         PinMap.cpp
*/

#include <cassert>
#include <functional>
#include <map>
#include <memory>

#include "Components.hpp"
#include "Exceptions.hpp"

void nts::PinMap::addInput(IComponent *component, std::size_t pin)
{
	assert(component != nullptr);
	m_pins[pin] = std::make_unique<InputPin>(component, pin);
}

void nts::PinMap::addOutput(IComponent *component, std::size_t pin)
{
	assert(component != nullptr);
	m_pins[pin] = std::make_unique<OutputPin>(component, pin);
}

void nts::PinMap::addInputRange(IComponent *component, std::size_t start, std::size_t end)
{
	for (std::size_t pin{ start }; pin <= end; ++pin) {
		addInput(component, pin);
	}
}

void nts::PinMap::addOutputRange(IComponent *component, std::size_t start, std::size_t end)
{
	for (std::size_t pin{ start }; pin <= end; ++pin) {
		addOutput(component, pin);
	}
}

nts::Tristate nts::PinMap::compute(std::size_t pin)
{
	assertExists(pin);
	return m_pins[pin]->compute();
}

nts::Tristate nts::PinMap::compute(TwoInputsGateFunc gate, std::size_t pinA, std::size_t pinB)
{
	assertExists(pinA);
	assertExists(pinB);
	return gate(m_pins[pinA]->compute(), m_pins[pinB]->compute());
}

nts::Tristate nts::PinMap::compute(OneInputGateFunc gate, std::size_t pin)
{
	assertExists(pin);
	return gate(m_pins[pin]->compute());
}

void nts::PinMap::link(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	assertExists(pin);
	m_pins[pin]->link(other, otherPin);
}

bool nts::PinMap::isLinked(std::size_t pin) const
{
	auto const pinPos{ m_pins.find(pin) };

	if (pinPos != m_pins.end()) {
		return pinPos->second->isLinked();
	}
	return false;
}

void nts::PinMap::reset()
{
	for (auto &pin : m_pins) {
		pin.second->reset();
	}
}

void nts::PinMap::dump() const
{
	for (auto const &pin : m_pins) {
		pin.second->dump();
	}
}

void nts::PinMap::assertExists(std::size_t pin) const
{
	if (m_pins.find(pin) == m_pins.end()) {
		throw InvalidPinException{ pin };
	}
}
