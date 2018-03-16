/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Prompt.hpp
*/

#pragma once

#include <string>

#include "Circuit/Circuit.hpp"
#include "CommandLine/Builtin.hpp"

namespace nts
{
	class Prompt
	{
	public:
		Prompt() = default;
		~Prompt() = default;

		Prompt(Prompt const &) = delete;
		Prompt(Prompt &&) = default;

		Prompt &operator=(Prompt const &) = delete;
		Prompt &operator=(Prompt &&) = default;

		void run(Circuit &circuit);

	private:
		void display() const;
		void read();
		void execute(Circuit &circuit);

		std::string m_command;
		bool m_hasExited{ false };
		Builtin m_builtin;
	};
}
