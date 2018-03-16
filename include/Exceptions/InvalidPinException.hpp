/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InvalidPinException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class InvalidPinException : public BaseException
	{
	public:
		explicit InvalidPinException(char const *pin);
		explicit InvalidPinException(std::string const &pin);
		explicit InvalidPinException(std::size_t pin);

		~InvalidPinException() = default;
	};
}
