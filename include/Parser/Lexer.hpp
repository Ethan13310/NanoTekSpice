/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Lexer.hpp
*/

#pragma once

#include <string>
#include <vector>

namespace nts
{
	class Lexer
	{
	public:
		explicit Lexer(std::string const &line);
		~Lexer() = default;

		Lexer(Lexer const &) = delete;
		Lexer(Lexer &&) = default;

		Lexer &operator=(Lexer const &) = delete;
		Lexer &operator=(Lexer &&) = default;

		std::string const &token(std::size_t index) const;
		std::size_t count() const;

	private:
		void purgeSpaces();
		void removeComment();
		void tokenize();

		std::string m_data;
		std::vector<std::string> m_tokens;
	};
}
