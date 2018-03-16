/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4013.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4013::C4013(std::string const &) :
	m_computed{ false }
{
	m_pins.addInputRange(this, 3, 6);
	m_pins.addInputRange(this, 8, 11);

	m_pins.addOutput(this, 1);
	m_pins.addOutput(this, 2);
	m_pins.addOutput(this, 7);
	m_pins.addOutputRange(this, 12, 14);

	m_state.fill(Tristate::True);
	m_clockState.fill(Tristate::Undefined);
	m_lastClockState.fill(Tristate::Undefined);
}

nts::Tristate nts::C4013::compute(std::size_t pin)
{
	if (pin == 0) {
		m_computed = false;
		m_pins.reset();
		return Tristate::Undefined;
	}

	if (!m_computed) {
		nextState(0);
		nextState(1);
		m_computed = true;
	}

	resetData();
	return computePin(pin);
}

nts::Tristate nts::C4013::computePin(std::size_t pin)
{
	switch (pin) {
	case 1:
		m_state[0] = computeOutput(0);
		return m_state[0];
	case 2:
		m_state[0] = computeOutput(0);
		return applyNot(0, m_state[0]);
	case 12:
		m_state[1] = computeOutput(1);
		return applyNot(1, m_state[1]);
	case 13:
		m_state[1] = computeOutput(1);
		return m_state[1];
	default:
		return m_pins.compute(pin);
	}
}

void nts::C4013::nextState(std::size_t i)
{
	auto const clockState{ m_pins.compute(3 + 8 * i) };

	if (m_lastClockState[i] == Tristate::True && clockState == Tristate::False) {
		m_clockState[i] = Tristate::False;
	}
	else if (m_lastClockState[i] == Tristate::False && clockState == Tristate::True) {
		m_clockState[i] = Tristate::True;
	}
	else {
		m_clockState[i] = Tristate::Undefined;
	}

	m_lastClockState[i] = clockState;
}

void nts::C4013::resetData()
{
	if (m_state[0] == Tristate::Undefined) {
		m_state[0] = Tristate::True;
	}

	if (m_state[1] == Tristate::Undefined) {
		m_state[1] = Tristate::True;
	}
}

nts::Tristate nts::C4013::computeOutput(std::size_t i)
{
	auto const reset{ m_pins.compute(4 + 6 * i) };
	auto const data{ m_pins.compute(5 + 4 * i) };
	auto const set{ m_pins.compute(6 + 2 * i) };

	if (reset == Tristate::False && set == Tristate::False) {
		if (m_clockState[i] == Tristate::True && data != Tristate::Undefined) {
			return data;
		}
		else if (m_clockState[i] == Tristate::False) {
			return m_state[i];
		}
	}
	else if (reset != Tristate::Undefined && set == Tristate::True) {
		return Tristate::True;
	}
	else if (reset == Tristate::True && set == Tristate::False) {
		return Tristate::False;
	}

	return Tristate::Undefined;
}

nts::Tristate nts::C4013::applyNot(std::size_t i, Tristate state)
{
	auto const reset{ m_pins.compute(4 + 6 * i) };
	auto const set{ m_pins.compute(6 + 2 * i) };

	if (reset == Tristate::True && set == Tristate::True) {
		return state;
	}
	return gate::Not(state);
}

void nts::C4013::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4013::dump() const
{
	std::cout << "[4013] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
