/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         LinkErrorException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::LinkErrorException::LinkErrorException(char const *message) :
	LinkErrorException{ std::string{ message } }
{}

nts::LinkErrorException::LinkErrorException(std::string const &message) :
	BaseException{ "Link Error: " + message }
{}
