/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Input.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

nts::Input::Input(std::string const &value) :
	m_pin{ this, 1 }
{
	setValue(value);
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pin.reset();
		return Tristate::Undefined;
	}
	else if (pin == 1) {
		return m_value;
	}
	throw nts::InvalidPinException{ pin };
}

void nts::Input::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	if (pin != 1) {
		throw nts::InvalidPinException{ pin };
	}
	m_pin.link(other, otherPin);
}

void nts::Input::dump() const
{
	std::cout << "[Input] " << utils::addr(this) << std::endl;
	std::cout << "\tValue = " << m_value << std::endl;
	m_pin.dump();
}

nts::Tristate nts::Input::value() const
{
	return m_value;
}

void nts::Input::setValue(Tristate value)
{
	m_value = value;
}

void nts::Input::setValue(int value)
{
	if (value == 1) {
		setValue(Tristate::True);
	}
	else if (value == 0) {
		setValue(Tristate::False);
	}
	else {
		setValue(Tristate::Undefined);
	}
}

void nts::Input::setValue(std::string const &value)
{
	try {
		setValue(std::stoi(value));
	}
	catch (std::exception const &) {
		setValue(Tristate::Undefined);
	}
}
