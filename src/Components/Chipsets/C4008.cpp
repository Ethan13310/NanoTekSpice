/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4008.cpp
*/

#include <iostream>
#include <string>
#include <utility>

#include "Components.hpp"
#include "Utils.hpp"

nts::C4008::C4008(std::string const &)
{
	m_pins.addInputRange(this, 1, 7);
	m_pins.addInput(this, 9);
	m_pins.addInput(this, 15);

	m_pins.addOutput(this, 8);
	m_pins.addOutputRange(this, 10, 14);
	m_pins.addOutput(this, 16);
}

nts::Tristate nts::C4008::compute(std::size_t pin)
{
	if (pin == 0) {
		m_pins.reset();
		return Tristate::Undefined;
	}

	switch (pin) {
	case 10:
		return computeS1().first;
	case 11:
		return computeS2().first;
	case 12:
		return computeS3().first;
	case 13:
		return computeS4().first;
	case 14:
		return computeCO();
	default:
		return m_pins.compute(pin);
	}
}

nts::Tristate nts::C4008::computeCO()
{
	return computeS4().second;
}

nts::C4008::SumResult nts::C4008::computeS4()
{
	auto carry{ computeS3().second };
	return std::make_pair(sum(m_pins.compute(15), m_pins.compute(1), carry), carry);
}

nts::C4008::SumResult nts::C4008::computeS3()
{
	auto carry{ computeS2().second };
	return std::make_pair(sum(m_pins.compute(2), m_pins.compute(3), carry), carry);
}

nts::C4008::SumResult nts::C4008::computeS2()
{
	auto carry{ computeS1().second };
	return std::make_pair(sum(m_pins.compute(4), m_pins.compute(5), carry), carry);
}

nts::C4008::SumResult nts::C4008::computeS1()
{
	auto carry{ m_pins.compute(9) };
	return std::make_pair(sum(m_pins.compute(6), m_pins.compute(7), carry), carry);
}

nts::Tristate nts::C4008::sum(Tristate a, Tristate b, Tristate &carry) const
{
	auto const ab{ gate::And(a, b) };     // a AND b
	auto const ac{ gate::And(a, carry) }; // a AND c
	auto const bc{ gate::And(b, carry) }; // b AND c
					      
	// a XOR b XOR c
	auto const result{ gate::Xor(gate::Xor(a, b), carry) };

	// (a AND b) OR (a AND c) OR (b AND c)
	carry = gate::Or(gate::Or(ab, ac), bc);

	return result;
}

void nts::C4008::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	m_pins.link(pin, other, otherPin);
}

void nts::C4008::dump() const
{
	std::cout << "[4008] " << utils::addr(this) << std::endl;
	m_pins.dump();
}
