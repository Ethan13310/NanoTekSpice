/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InputPin.cpp
*/

#include "Components.hpp"
#include "Exceptions.hpp"

nts::InputPin::InputPin(IComponent *component, std::size_t pin) :
	Pin{ component, pin },
	m_state{ Tristate::Undefined },
	m_computed{ false }
{}

void nts::InputPin::link(IComponent &other, std::size_t otherPin)
{
	if (isSelf(other, otherPin)) {
		throw LinkErrorException{ "Pin cannot be linked to itself." };
	}

	if (!linkExists(other, otherPin)) {
		if (isLinked()) {
			throw LinkErrorException{ "Input pin cannot be linked multiple times." };
		}

		m_links.emplace_back(other, otherPin);
		other.setLink(otherPin, m_component, m_pin);
	}
}

nts::Tristate nts::InputPin::compute()
{
	if (isLinked()) {
		if (!m_computed) {
			m_computed = true;
			m_state = m_links[0].first.get().compute(m_links[0].second);
		}
		return m_state;
	}
	else {
		return Tristate::Undefined;
	}
}

void nts::InputPin::reset()
{
	m_computed = false;
}
