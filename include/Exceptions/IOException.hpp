/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         IOException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class IOException : public BaseException
	{
	public:
		IOException(char const *message);
		IOException(std::string const &message);

		~IOException() = default;
	};
}
