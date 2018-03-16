/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Main.cpp
*/

#include <iostream>

#include "Circuit.hpp"
#include "CommandLine.hpp"
#include "Exceptions.hpp"

int main(int argc, char const **argv)
{
	if (argc < 2) {
		std::cout << "Usage: ./nanotekspice <filepath> [<input=value> ...]" << std::endl;
		return 0;
	}

	try {
		nts::Circuit circuit{ argc, argv };
		circuit.simulate();
		circuit.display();

		nts::Prompt prompt;
		prompt.run(circuit);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}

	return 0;
}
