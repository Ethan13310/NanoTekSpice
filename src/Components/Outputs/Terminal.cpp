/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Terminal.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

nts::Terminal::Terminal() :
	Output{}
{
	m_pins.addInputRange(this, 1, 9);
}

nts::Tristate nts::Terminal::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pins.reset();
		m_displayable = false;
		m_computed = false;
	}
	else if (!m_computed) {
		computeData();
		m_computed = true;

		if (m_pins.compute(9) == Tristate::True) {
			m_displayable = true;
		}
	}

	return Tristate::Undefined;
}

void nts::Terminal::computeData()
{
	m_data = 0;

	auto toInt = [](Tristate state) {
		if (state == Tristate::True) {
			return 1;
		}
		return 0;
	};

	for (std::size_t i{ 0 }; i < 8; ++i) {
		m_data |= toInt(m_pins.compute(i + 1)) << i;
	}
}

void nts::Terminal::dump() const
{
	std::cout << "[Terminal] " << utils::addr(this) << std::endl;
	std::cout << "\tValue = " << m_data << std::endl;
	m_pins.dump();
}

void nts::Terminal::display() const
{
	if (m_displayable) {
		std::cout << m_data;
	}
}

void nts::Terminal::display(std::string const &) const
{
	display();
}
