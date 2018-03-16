/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4040.cpp
*/

#include <iostream>
#include <string>
#include <unordered_map>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4040::C4040(std::string const &) :
	m_counter{ 0 },
	m_lastClockState{ Tristate::Undefined },
	m_computed{ false }
{
	m_pins.addInput(this, 10);
	m_pins.addInput(this, 11);

	m_pins.addOutputRange(this, 1, 9);
	m_pins.addOutputRange(this, 12, 16);

	m_pinToBit[1] = 12;
	m_pinToBit[2] = 6;
	m_pinToBit[3] = 5;
	m_pinToBit[4] = 7;
	m_pinToBit[5] = 4;
	m_pinToBit[6] = 3;
	m_pinToBit[7] = 2;
	m_pinToBit[9] = 1;
	m_pinToBit[12] = 9;
	m_pinToBit[13] = 8;
	m_pinToBit[14] = 10;
	m_pinToBit[15] = 11;
}

nts::Tristate nts::C4040::compute(std::size_t pin)
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

	return m_pins.compute(pin);
}

void nts::C4040::nextState()
{
	auto const clockState{ m_pins.compute(10) };

	if (m_pins.compute(11) == Tristate::True) {
		reset();
	}
	// State change : 1 -> 0
	else if (m_lastClockState == Tristate::True && clockState == Tristate::False) {
		increment();
	}

	m_lastClockState = clockState;
}

nts::Tristate nts::C4040::bit(std::size_t i) const
{
	if (i > 0 && i <= 12) {
		if ((m_counter >> (i - 1)) & 1) {
			return Tristate::True;
		}
		else {
			return Tristate::False;
		}
	}
	return Tristate::Undefined;
}

void nts::C4040::increment()
{
	if (m_counter < 0xFFF) {
		++m_counter;
	}
	else {
		reset();
	}
}

void nts::C4040::reset()
{
	m_counter = 0;
}

void nts::C4040::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4040::dump() const
{
	std::cout << "[4040] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
