/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         BaseException.hpp
*/

#pragma once

#include <exception>
#include <string>

namespace nts
{
	class BaseException : public std::exception
	{
	public:
		BaseException() = default;
		explicit BaseException(char const *message);
		explicit BaseException(std::string const &message);

		~BaseException() = default;

		void update(char const *message);
		void update(std::string const &message);

		void append(char const *message);
		void append(std::string const &message);

		char const *what() const noexcept;

	private:
		std::string m_message;
	};
}
