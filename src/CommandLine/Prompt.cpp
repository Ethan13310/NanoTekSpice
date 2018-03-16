/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Prompt.cpp
*/

#include <iostream>

#include "Circuit.hpp"
#include "CommandLine.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

void nts::Prompt::run(Circuit &circuit)
{
	m_hasExited = false;

	while (!m_hasExited) {
		try {
			display();
			read();
			execute(circuit);
		}
		catch (nts::EOFException const &) {
			m_hasExited = true;
		}
	}
}

void nts::Prompt::display() const
{
	std::cout << "> " << std::flush;
}

void nts::Prompt::read()
{
	std::getline(std::cin, m_command);

	if (std::cin.eof()) {
		std::cin.clear();
		throw EOFException{};
	}

	utils::trim(m_command);
}

void nts::Prompt::execute(Circuit &circuit)
{
	if (m_command.size() > 0) {
		try {
			if (!m_builtin(circuit, m_command)) {
				m_hasExited = true;
			}
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
