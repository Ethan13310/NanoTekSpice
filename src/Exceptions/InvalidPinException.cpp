/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InvalidPinException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::InvalidPinException::InvalidPinException(char const *pin) :
	InvalidPinException{ std::string{ pin } }
{}

nts::InvalidPinException::InvalidPinException(std::string const &pin) :
	BaseException{ "Error: Pin '" + pin + "' does not exist." }
{}

nts::InvalidPinException::InvalidPinException(std::size_t pin) :
	InvalidPinException{ std::to_string(pin) }
{}
