/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InputErrorException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::InputErrorException::InputErrorException(char const *message) :
	InputErrorException{ std::string{ message } }
{}

nts::InputErrorException::InputErrorException(std::string const &message) :
	BaseException{ "Input Error: " + message }
{}
