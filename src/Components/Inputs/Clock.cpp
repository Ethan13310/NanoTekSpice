/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Clock.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

nts::Clock::Clock(std::string const &value) :
	Input{ value }
{}

void nts::Clock::dump() const
{
	std::cout << "[Clock] " << utils::addr(this) << std::endl;
	std::cout << "\tValue = " << m_value << std::endl;
	m_pin.dump();
}

void nts::Clock::setValue(Tristate)
{
	throw InputErrorException{ "'Clock' value cannot be changed." };
}

void nts::Clock::reverse()
{
	if (m_value == Tristate::True) {
		m_value = Tristate::False;
	}
	else if (m_value == Tristate::False) {
		m_value = Tristate::True;
	}
}
