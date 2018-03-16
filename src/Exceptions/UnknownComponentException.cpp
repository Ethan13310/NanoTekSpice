/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         UnknownComponentException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::UnknownComponentException::UnknownComponentException(char const *cmd) :
	UnknownComponentException{ std::string{ cmd } }
{}

nts::UnknownComponentException::UnknownComponentException(std::string const &cmd) :
	BaseException{ cmd + ": unknown component." }
{}
