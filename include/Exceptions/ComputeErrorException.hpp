/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         ComputeErrorException.hpp
*/

#pragma once

#include <string>

#include "Exceptions/BaseException.hpp"

namespace nts
{
	class ComputeErrorException : public BaseException
	{
	public:
		explicit ComputeErrorException(char const *message);
		explicit ComputeErrorException(std::string const &message);

		~ComputeErrorException() = default;
	};
}
