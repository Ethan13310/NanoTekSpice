/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         False.cpp
*/

#include <iostream>
#include <string>

#include "Components.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

nts::False::False() :
	Input{ "0" }
{}

void nts::False::dump() const
{
	std::cout << "[False] " << utils::addr(this) << std::endl;
	std::cout << "\tValue = " << m_value << std::endl;
	m_pin.dump();
}

void nts::False::setValue(Tristate)
{
	throw InputErrorException{ "'False' value cannot be changed." };
}
