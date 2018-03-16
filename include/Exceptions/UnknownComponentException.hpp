/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         UnknownComponentException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class UnknownComponentException : public BaseException
	{
	public:
		explicit UnknownComponentException(char const *name);
		explicit UnknownComponentException(std::string const &name);

		~UnknownComponentException() = default;
	};
}
