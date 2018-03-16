/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Section.hpp
*/

#pragma once

#include <string>

#include "Parser/Lexer.hpp"
#include "Parser/Tree.hpp"

namespace nts
{
	class Section final
	{
	public:
		explicit Section(Lexer const &line);
		explicit Section(std::string const& line);

		~Section() = default;

		Section(Section const &) = default;
		Section(Section &&) = default;

		Section &operator=(Section const &) = default;
		Section &operator=(Section &&) = default;

		std::string const &name() const;
		void initializeNode(Tree::Node &node) const;

	private:
		void parse(std::string const &token);

		std::string m_name;
	};
}
