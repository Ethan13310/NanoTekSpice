/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Arguments.cpp
*/

#include <cassert>
#include <string>
#include <vector>

#include "Exceptions.hpp"
#include "Parser.hpp"

nts::Arguments::Arguments(int argc, char const **argv)
{
	if (argc < 2) {
		throw InvalidArgumentException{ "No file specified." };
	}

	assert(argc >= 2 && argv[1] != nullptr);

	m_filepath = argv[1];
	std::size_t const count{ static_cast<std::size_t>(argc) };

	for (std::size_t i{ 2 }; i < count; ++i) {
		assert(argv[i] != nullptr);
		m_inputs.emplace_back(argv[i]);
	}
}

std::string const &nts::Arguments::filepath() const
{
	return m_filepath;
}

nts::InputValue const &nts::Arguments::findInput(std::string const &name) const
{
	for (auto const &input : m_inputs) {
		if (input.name == name) {
			return input;
		}
	}
	
	throw InputErrorException{ "'" + name + "' is not initialized." };
}
