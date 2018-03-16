/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         ComputeErrorException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::ComputeErrorException::ComputeErrorException(char const *message) :
	ComputeErrorException{ std::string{ message } }
{}

nts::ComputeErrorException::ComputeErrorException(std::string const &message) :
	BaseException{ "Compute Error: " + message }
{}
