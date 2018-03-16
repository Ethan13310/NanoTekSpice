/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         EOFException.hpp
*/

#pragma once

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class EOFException : public BaseException
	{
	public:
		EOFException();
		~EOFException() = default;
	};
}
