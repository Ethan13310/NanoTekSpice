/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4069.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4069::C4069(std::string const &)
{
	m_pins.addInput(this, 1);
	m_pins.addInput(this, 3);
	m_pins.addInput(this, 5);
	m_pins.addInput(this, 9);
	m_pins.addInput(this, 11);
	m_pins.addInput(this, 13);

	m_pins.addOutput(this, 2);
	m_pins.addOutput(this, 4);
	m_pins.addOutput(this, 6);
	m_pins.addOutput(this, 7);
	m_pins.addOutput(this, 8);
	m_pins.addOutput(this, 10);
	m_pins.addOutput(this, 12);
	m_pins.addOutput(this, 14);
}

nts::Tristate nts::C4069::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pins.reset();
		return Tristate::Undefined;
	}

	switch (pin) {
	case 2:
		return m_pins.compute(gate::Not, 1);
	case 4:
		return m_pins.compute(gate::Not, 3);
	case 6:
		return m_pins.compute(gate::Not, 5);
	case 8:
		return m_pins.compute(gate::Not, 9);
	case 10:
		return m_pins.compute(gate::Not, 11);
	case 12:
		return m_pins.compute(gate::Not, 13);
	default:
		return m_pins.compute(pin);
	}
}

void nts::C4069::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4069::dump() const
{
	std::cout << "[4069] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
