/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Circuit.hpp
*/

#pragma once

#include "Circuit/Executor.hpp"
#include "Parser/Tree.hpp"

namespace nts
{
	class Circuit
	{
	public:
		Circuit(int argc, char const **argv);
		~Circuit() = default;

		Circuit(Circuit const &) = delete;
		Circuit(Circuit &&) = default;

		Circuit &operator=(Circuit const &) = delete;
		Circuit &operator=(Circuit &&) = default;

		void display() const;
		void simulate();
		void loop();
		void dump() const;
		void updateInput(InputValue const &input);

		static void stop(int signal);

	private:
		static bool m_stop;

		Tree m_tree;
		Executor m_executor;
	};
}
