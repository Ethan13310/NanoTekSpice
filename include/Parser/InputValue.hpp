/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InputValue.hpp
*/

#pragma once

#include <string>

namespace nts
{
	class InputValue final
	{
	public:
		explicit InputValue(std::string const &arg);
		~InputValue() = default;

		InputValue(InputValue const &) = default;
		InputValue(InputValue &&) = default;

		InputValue& operator=(InputValue const &) = default;
		InputValue& operator=(InputValue &&) = default;

		// Public accessibility is on purpose
		std::string name;
		std::string value;

	private:
		void parse(std::string const &arg, std::size_t pos);
	};
}
