/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Circuit.cpp
*/

#include <csignal>

#include "Circuit.hpp"
#include "Parser.hpp"

bool nts::Circuit::m_stop{ false };

nts::Circuit::Circuit(int argc, char const **argv) :
	m_tree{ argc, argv },
	m_executor{ m_tree }
{}

void nts::Circuit::display() const
{
	m_executor.display();
}

void nts::Circuit::simulate()
{
	m_executor.simulate();
	m_executor.reverseClocks();
}

void nts::Circuit::loop()
{
	m_stop = false;

	std::signal(SIGINT, Circuit::stop);

	while (!m_stop) {
		simulate();
	}

	std::signal(SIGINT, SIG_DFL);
}

void nts::Circuit::dump() const
{
	m_executor.dump();
}

void nts::Circuit::updateInput(InputValue const &input)
{
	m_executor.updateInput(input);
}

void nts::Circuit::stop(int)
{
	m_stop = true;
}
