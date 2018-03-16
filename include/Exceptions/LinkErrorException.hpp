/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         LinkErrorException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class LinkErrorException : public BaseException
	{
	public:
		LinkErrorException(char const *message);
		LinkErrorException(std::string const &message);

		~LinkErrorException() = default;
	};
}
