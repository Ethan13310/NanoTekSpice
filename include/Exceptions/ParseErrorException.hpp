/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         ParseErrorException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class ParseErrorException : public BaseException
	{
	public:
		ParseErrorException(char const *message);
		ParseErrorException(std::string const &message);

		~ParseErrorException() = default;
	};
}
