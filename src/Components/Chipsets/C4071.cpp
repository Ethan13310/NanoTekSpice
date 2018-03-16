/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4071.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4071::C4071(std::string const &)
{
	m_pins.addInput(this, 1);
	m_pins.addInput(this, 2);
	m_pins.addInput(this, 5);
	m_pins.addInput(this, 6);
	m_pins.addInput(this, 8);
	m_pins.addInput(this, 9);
	m_pins.addInput(this, 12);
	m_pins.addInput(this, 13);

	m_pins.addOutput(this, 3);
	m_pins.addOutput(this, 4);
	m_pins.addOutput(this, 7);
	m_pins.addOutput(this, 10);
	m_pins.addOutput(this, 11);
	m_pins.addOutput(this, 14);
}

nts::Tristate nts::C4071::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pins.reset();
		return Tristate::Undefined;
	}

	switch (pin) {
	case 3:
		return m_pins.compute(gate::Or, 1, 2);
	case 4:
		return m_pins.compute(gate::Or, 5, 6);
	case 10:
		return m_pins.compute(gate::Or, 8, 9);
	case 11:
		return m_pins.compute(gate::Or, 12, 13);
	default:
		return m_pins.compute(pin);
	}
}

void nts::C4071::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4071::dump() const
{
	std::cout << "[4071] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
