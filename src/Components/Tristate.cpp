/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Tristate.cpp
*/

#include <ostream>

#include "Utils.hpp"

std::ostream &operator<<(std::ostream &out, nts::Tristate state)
{
	out << utils::toString(state);
	return out;
}
