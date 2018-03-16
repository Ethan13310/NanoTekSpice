/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Link.hpp
*/

#pragma once

#include <string>
#include <utility>

#include "Parser/Lexer.hpp"
#include "Parser/Tree.hpp"

namespace nts
{
	class Link final
	{
	public:
		struct Pair
		{
			std::string name;
			std::size_t pin;
		};

		explicit Link(Lexer const &line);
		explicit Link(std::string const &line);

		~Link() = default;

		Link(Link const &) = default;
		Link(Link &&) = default;

		Link &operator=(Link const &) = default;
		Link &operator=(Link &&) = default;

		Pair const &first() const;
		Pair const &second() const;

		void initializeNode(Tree::Node &node) const;

	private:
		void parse(std::string const &first, std::string const &second);
		void validate(std::string const &link) const;
		Pair split(std::string const &link) const;

		Pair m_first;
		Pair m_second;

		std::string m_firstLink;
		std::string m_secondLink;
	};
}
