/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         UnknownCommandException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::UnknownCommandException::UnknownCommandException(char const *cmd) :
	UnknownCommandException{ std::string{ cmd } }
{}

nts::UnknownCommandException::UnknownCommandException(std::string const &cmd) :
	BaseException{ cmd + ": unknown command." }
{}
