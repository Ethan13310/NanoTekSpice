/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Output.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

nts::Output::Output()
{
	m_pins.addInput(this, 1);
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pins.reset();
		return Tristate::Undefined;
	}

	if (!m_pins.isLinked(1)) {
		throw LinkErrorException{ "Output is not linked to anything." };
	}

	m_value = m_pins.compute(1);
	return m_value;
}

void nts::Output::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::Output::dump() const
{
	std::cout << "[Output] " << utils::addr(this) << std::endl;
	std::cout << "\tValue = " << m_value << std::endl;
	m_pins.dump();
}

void nts::Output::display() const
{
	std::cout << m_value << std::endl;
}

void nts::Output::display(std::string const &name) const
{
	std::cout << name;
	display();
}
