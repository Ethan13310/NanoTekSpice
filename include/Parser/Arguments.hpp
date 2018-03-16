/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Arguments.hpp
*/

#pragma once

#include <string>
#include <vector>

#include "Parser/InputValue.hpp"

namespace nts
{
	class Arguments
	{
	public:
		Arguments(int argc, char const **argv);
		~Arguments() = default;

		Arguments(Arguments const &) = delete;
		Arguments(Arguments &&) = default;

		Arguments& operator=(Arguments const &) = delete;
		Arguments& operator=(Arguments &&) = default;

		std::string const &filepath() const;
		InputValue const &findInput(std::string const &name) const;

	private:
		std::string m_filepath;
		std::vector<InputValue> m_inputs;
	};
}
