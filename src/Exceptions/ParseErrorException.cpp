/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         ParseErrorException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::ParseErrorException::ParseErrorException(char const *message) :
	ParseErrorException{ std::string{ message } }
{}

nts::ParseErrorException::ParseErrorException(std::string const &message) :
	BaseException{ "Parse Error: " + message }
{}
