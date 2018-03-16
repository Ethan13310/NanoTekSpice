/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InputErrorException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class InputErrorException : public BaseException
	{
	public:
		InputErrorException(char const *message);
		InputErrorException(std::string const &message);

		~InputErrorException() = default;
	};
}
