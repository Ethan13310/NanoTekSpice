/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         OutputPin.cpp
*/

#include "Components.hpp"
#include "Exceptions.hpp"

nts::OutputPin::OutputPin(IComponent *component, std::size_t pin) :
	Pin{ component, pin }
{}

void nts::OutputPin::link(IComponent &other, std::size_t otherPin)
{
	if (isSelf(other, otherPin)) {
		throw LinkErrorException{ "Pin cannot be linked to itself." };
	}
	
	if (!linkExists(other, otherPin)) {
		m_links.emplace_back(other, otherPin);
		other.setLink(otherPin, m_component, m_pin);
	}
}

nts::Tristate nts::OutputPin::compute()
{
	return Tristate::Undefined;
}

void nts::OutputPin::reset()
{
	// Nothing to do
}
