/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         IOException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::IOException::IOException(char const *message) :
	BaseException{ message }
{}

nts::IOException::IOException(std::string const &message) :
	BaseException{ message }
{}
