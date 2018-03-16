/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         UnknownCommandException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class UnknownCommandException : public BaseException
	{
	public:
		explicit UnknownCommandException(char const *cmd);
		explicit UnknownCommandException(std::string const &cmd);

		~UnknownCommandException() = default;
	};
}
