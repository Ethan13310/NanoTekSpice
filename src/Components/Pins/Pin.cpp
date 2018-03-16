/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Pin.cpp
*/

#include <iostream>
#include <vector>

#include "Components.hpp"
#include "Utils.hpp"

nts::Pin::Pin(IComponent *component, std::size_t pin) :
	m_component{ *component },
	m_pin{ pin }
{}

bool nts::Pin::isLinked() const
{
	return m_links.size() > 0;
}

bool nts::Pin::isSelf(IComponent &other, std::size_t otherPin) const
{
	return &m_component == &other && m_pin == otherPin;
}

bool nts::Pin::linkExists(IComponent &other, std::size_t otherPin) const
{
	for (auto const &link : m_links) {
		if (&link.first.get() == &other && link.second == otherPin) {
			return true;
		}
	}
	return false;
}

void nts::Pin::dump() const
{
	if (m_links.size() == 0) {
		std::cout << "\tPin[" << m_pin << "] = Not Linked" << std::endl;
	}
	else if (m_links.size() == 1) {
		std::cout << "\tPin[" << m_pin << "] = Linked to ";
		std::cout << utils::toString(m_links[0].first, m_links[0].second) << std::endl;
	}
	else {
		std::size_t i{ 1 };

		for (auto const &link : m_links) {
			std::cout << "\tPin[" << m_pin << "] (" << i++ << ") = Linked to ";
			std::cout << utils::toString(link.first, link.second) << std::endl;
		}
	}
}
