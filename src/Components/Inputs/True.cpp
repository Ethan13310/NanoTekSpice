/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         True.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

nts::True::True() :
	Input{ "1" }
{}

void nts::True::dump() const
{
	std::cout << "[True] " << utils::addr(this) << std::endl;
	std::cout << "\tValue = " << m_value << std::endl;
	m_pin.dump();
}

void nts::True::setValue(Tristate)
{
	throw InputErrorException{ "'True' value cannot be changed." };
}
