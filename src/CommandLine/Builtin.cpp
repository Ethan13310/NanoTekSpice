/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Builtin.cpp
*/

#include <string>
#include <unordered_map>

#include "Circuit.hpp"
#include "CommandLine.hpp"
#include "Exceptions.hpp"
#include "Parser.hpp"

nts::Builtin::Builtin()
{
	m_commands["display"] = &Circuit::display;
	m_commands["simulate"] = &Circuit::simulate;
	m_commands["loop"] = &Circuit::loop;
	m_commands["dump"] = &Circuit::dump;
}

bool nts::Builtin::operator()(Circuit &circuit, std::string const &cmd) const
{
	if (cmd == "exit") {
		return false;
	}

	if (cmd.find('=') != std::string::npos) {
		circuit.updateInput(InputValue{ cmd });
		return true;
	}

	auto it{ m_commands.find(cmd) };

	if (it != m_commands.end()) {
		it->second(circuit);
		return true;
	}

	throw UnknownCommandException{ cmd };
}
