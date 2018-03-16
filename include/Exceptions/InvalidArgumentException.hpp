/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InvalidArgumentException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class InvalidArgumentException : public BaseException
	{
	public:
		InvalidArgumentException(char const *message);
		InvalidArgumentException(std::string const &message);

		~InvalidArgumentException() = default;
	};
}
