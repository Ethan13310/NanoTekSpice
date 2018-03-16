/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4017.cpp
*/

#include <iostream>
#include <string>
#include <unordered_map>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4017::C4017(std::string const &) :
	m_counter{ 1 },
	m_lastClockState{ Tristate::Undefined },
	m_computed{ false }
{
	m_pins.addInputRange(this, 13, 15);

	m_pins.addOutputRange(this, 1, 12);
	m_pins.addOutput(this, 16);

	m_pinToBit[1] = 6;
	m_pinToBit[2] = 2;
	m_pinToBit[3] = 1;
	m_pinToBit[4] = 3;
	m_pinToBit[5] = 7;
	m_pinToBit[6] = 8;
	m_pinToBit[7] = 4;
	m_pinToBit[9] = 9;
	m_pinToBit[10] = 5;
	m_pinToBit[11] = 10;
}

nts::Tristate nts::C4017::compute(std::size_t pin)
{
	if (pin == 0) {
		m_computed = false;
		m_pins.reset();
		return Tristate::Undefined;
	}

	if (!m_computed) {
		nextState();
		m_computed = true;
	}

	if (m_pinToBit.find(pin) != m_pinToBit.end()) {
		return bit(m_pinToBit[pin]);
	}
	else if (pin == 12) {
		return computePin12();
	}

	return m_pins.compute(pin);
}

nts::Tristate nts::C4017::computePin12()
{
	for (std::size_t i{ 6 }; i <= 10; ++i) {
		if (bit(i) == Tristate::True) {
			return Tristate::False;
		}
	}
	return Tristate::True;
}

void nts::C4017::nextState()
{
	auto cp1{ gate::Not(m_pins.compute(13)) };

	if (cp1 == Tristate::Undefined) {
		cp1 = Tristate::True;
	}

	auto const clockState{ gate::And(cp1, m_pins.compute(14)) };

	if (m_pins.compute(15) == Tristate::True) {
		reset();
	}
	// State change : 0 -> 1
	else if (m_lastClockState == Tristate::False && clockState == Tristate::True) {
		increment();
	}

	m_lastClockState = clockState;
}

nts::Tristate nts::C4017::bit(std::size_t i) const
{
	if (i > 0 && i <= 10) {
		if ((m_counter >> (i - 1)) & 1) {
			return Tristate::True;
		}
		else {
			return Tristate::False;
		}
	}
	return Tristate::Undefined;
}

void nts::C4017::increment()
{
	if (m_counter >= 0x3FF) {
		m_counter = 1;
	}
	else {
		m_counter <<= 1;
	}
}

void nts::C4017::reset()
{
	m_counter = 1;
}

void nts::C4017::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4017::dump() const
{
	std::cout << "[4017] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
