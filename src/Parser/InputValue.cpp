/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InputValue.cpp
*/

#include <string>

#include "Exceptions.hpp"
#include "Parser.hpp"
#include "Utils.hpp"

nts::InputValue::InputValue(std::string const &arg)
{
	auto const pos{ arg.find_first_of('=') };

	if (pos != arg.find_last_of('=')) {
		throw InputErrorException{ "Invalid syntax (unexpected token '=')." };
	}

	if (pos == std::string::npos) {
		throw InputErrorException{ "Missing value." };
	}

	parse(arg, pos);
}

void nts::InputValue::parse(std::string const &arg, std::size_t pos)
{
	std::string inputName{ arg.substr(0, pos) };
	std::string inputValue{ arg.substr(pos + 1) };

	utils::trim(inputName);
	utils::trim(inputValue);

	if (inputName.size() == 0) {
		throw InputErrorException{ "Missing name." };
	}

	if (inputValue != "0" && inputValue != "1") {
		throw InputErrorException{ "Input value must be either 0 or 1." };
	}

	name = inputName;
	value = inputValue;
}
