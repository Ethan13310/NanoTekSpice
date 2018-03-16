/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InvalidArgumentException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::InvalidArgumentException::InvalidArgumentException(char const *message) :
	BaseException{ message }
{}

nts::InvalidArgumentException::InvalidArgumentException(std::string const &message) :
	BaseException{ message }
{}
