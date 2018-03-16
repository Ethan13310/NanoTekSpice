/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4094.cpp
*/

#include <iostream>
#include <string>
#include <unordered_map>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4094::C4094(std::string const &) :
	m_lastClockState{ Tristate::Undefined },
	m_clockState{ Tristate::Undefined },
	m_computed{ false }
{
	m_pins.addInputRange(this, 1, 3);
	m_pins.addInput(this, 15);

	m_pins.addOutputRange(this, 4, 7);
	m_pins.addOutputRange(this, 9, 14);
	m_pins.addOutput(this, 8);
	m_pins.addOutput(this, 16);

	m_bits.fill(Tristate::Undefined);

	m_qs = Tristate::False;
	m_qsp = Tristate::False;

	m_pinToBit[4] = 0;
	m_pinToBit[5] = 1;
	m_pinToBit[6] = 2;
	m_pinToBit[7] = 3;
	m_pinToBit[14] = 4;
	m_pinToBit[13] = 5;
	m_pinToBit[12] = 6;
	m_pinToBit[11] = 7;
}

nts::Tristate nts::C4094::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pins.reset();
		m_computed = false;
		return Tristate::Undefined;
	}

	if (!m_computed) {
		nextState();
		computeOutput();
		m_computed = true;
	}

	if (m_pinToBit.find(pin) != m_pinToBit.end()) {
		return m_bits[m_pinToBit[pin]];
	}
	else if (pin == 9) {
		return m_qs;
	}
	else if (pin == 10) {
		return m_qsp;
	}

	return m_pins.compute(pin);
}

void nts::C4094::computeOutput()
{
	auto const enableOutput{ m_pins.compute(15) };

	if (enableOutput == Tristate::True) {
		for (auto &bit : m_bits) {
			if (bit == Tristate::Undefined) {
				bit = Tristate::False;
			}
		}

		auto const strobe{ m_pins.compute(1) };

		if (strobe == Tristate::True) {
			auto const data{ m_pins.compute(2) };

			if (m_clockState == Tristate::True) {
				m_qs = m_bits[6]; // Q7
				shift();
				m_bits[0] = data; // Q1
			}
			else if (m_clockState == Tristate::False && data == Tristate::True) {
				m_qsp = m_bits[6];
			}
		}
		else if (strobe == Tristate::False && m_clockState == Tristate::True) {
			m_qs = m_bits[6];
		}
	}
	else if (enableOutput == Tristate::False) {
		if (m_clockState == Tristate::True) {
			m_qs = (m_bits[6] != Tristate::Undefined) ? m_bits[6] : Tristate::False;
		}
		else if (m_clockState == Tristate::False) {
			m_qsp = (m_bits[6] != Tristate::Undefined) ? m_bits[6] : Tristate::False;
		}
		m_bits.fill(Tristate::Undefined);
	}
}

void nts::C4094::shift()
{
	for (std::size_t i{ 0 }; i < m_bits.size() - 1; ++i) {
		m_bits[m_bits.size() - i - 1] = m_bits[m_bits.size() - i - 2];
	}
}

void nts::C4094::nextState()
{
	auto const clockState{ m_pins.compute(3) };

	if (m_lastClockState == Tristate::True && clockState == Tristate::False) {
		m_clockState = Tristate::False;
	}
	else if (m_lastClockState == Tristate::False && clockState == Tristate::True) {
		m_clockState = Tristate::True;
	}
	else {
		m_clockState = Tristate::Undefined;
	}

	m_lastClockState = clockState;
}

void nts::C4094::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4094::dump() const
{
	std::cout << "[4094] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
