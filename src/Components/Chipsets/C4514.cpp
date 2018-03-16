/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4514.cpp
*/

#include <array>
#include <iostream>
#include <string>
#include <unordered_map>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4514::C4514(std::string const &) :
	m_computed{ false }
{
	m_pins.addInputRange(this, 1, 3);
	m_pins.addInputRange(this, 21, 23);

	m_pins.addOutputRange(this, 4, 20);
	m_pins.addOutput(this, 24);

	// m_truthTable[pin] = { D, C, B, A };

	m_truthTable[4] = { Tristate::False, Tristate::True, Tristate::True, Tristate::True };
	m_truthTable[5] = { Tristate::False, Tristate::True, Tristate::True, Tristate::False };
	m_truthTable[6] = { Tristate::False, Tristate::True, Tristate::False, Tristate::True };
	m_truthTable[7] = { Tristate::False, Tristate::True, Tristate::False, Tristate::False };
	m_truthTable[8] = { Tristate::False, Tristate::False, Tristate::True, Tristate::True };
	m_truthTable[9] = { Tristate::False, Tristate::False, Tristate::False, Tristate::True };
	m_truthTable[10] = { Tristate::False, Tristate::False, Tristate::True, Tristate::False };
	m_truthTable[11] = { Tristate::False, Tristate::False, Tristate::False, Tristate::False };
	m_truthTable[13] = { Tristate::True, Tristate::True, Tristate::False, Tristate::True };
	m_truthTable[14] = { Tristate::True, Tristate::True, Tristate::False, Tristate::False };
	m_truthTable[15] = { Tristate::True, Tristate::True, Tristate::True, Tristate::True };
	m_truthTable[16] = { Tristate::True, Tristate::True, Tristate::True, Tristate::False };
	m_truthTable[17] = { Tristate::True, Tristate::False, Tristate::False, Tristate::True };
	m_truthTable[18] = { Tristate::True, Tristate::False, Tristate::False, Tristate::False };
	m_truthTable[19] = { Tristate::True, Tristate::False, Tristate::True, Tristate::True };
	m_truthTable[20] = { Tristate::True, Tristate::False, Tristate::True, Tristate::False };

	m_data.fill(Tristate::Undefined);
}

nts::Tristate nts::C4514::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pins.reset();
		m_computed = false;
		return Tristate::Undefined;
	}

	if (!m_computed) {
		saveData();
		m_computed = true;
	}

	if (pin >= 4 && pin <= 20 && pin != 12) {
		return computeOutput(pin);
	}

	return m_pins.compute(pin);
}

void nts::C4514::saveData()
{
	if (m_pins.compute(1) == Tristate::True) {
		m_data[0] = m_pins.compute(2);
		m_data[1] = m_pins.compute(3);
		m_data[2] = m_pins.compute(21);
		m_data[3] = m_pins.compute(22);
	}
}

nts::Tristate nts::C4514::computeOutput(std::size_t pin)
{
	if (m_pins.compute(23) == Tristate::True) {
		return Tristate::False;
	}

	auto const output{ selectOutput() };

	if (output == 0) {
		return Tristate::Undefined;
	}
	else if (output == pin) {
		return Tristate::True;
	}
	else {
		return Tristate::False;
	}
}

std::size_t nts::C4514::selectOutput() const
{
	for (auto const &out : m_truthTable) {
		if (isTrue(out.second)) {
			return out.first;
		}
	}
	return 0;
}

bool nts::C4514::isTrue(DataArray const &out) const
{
	for (std::size_t i{ 0 }; i < m_data.size(); ++i) {
		if (m_data[i] != out[m_data.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

void nts::C4514::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4514::dump() const
{
	std::cout << "[4514] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
