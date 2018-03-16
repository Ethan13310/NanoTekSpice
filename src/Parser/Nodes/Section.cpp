/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Section.hpp
*/

#include <cassert>
#include <string>

#include "Exceptions.hpp"
#include "Parser.hpp"

nts::Section::Section(Lexer const &line)
{
	if (line.count() == 1) {
		auto const token{ line.token(0) };

		if (token.front() == '.') {
			parse(token);
		}
		else {
			throw ParseErrorException{ "Invalid section declaration (missing '.')" };
		}
	}
	else {
		auto const count{ std::to_string(line.count()) };
		throw ParseErrorException{ "Unexpected token (expected 1 token, got " + count + ")" };
	}
}

nts::Section::Section(std::string const &line) :
	Section{ Lexer{ line } }
{}

std::string const &nts::Section::name() const
{
	return m_name;
}

void nts::Section::initializeNode(Tree::Node &node) const
{
	node.type = Tree::Node::Type::Section;
	node.name = m_name;
	node.value.clear();
}

void nts::Section::parse(std::string const &token)
{
	assert(token.size() != 0);

	if (token.size() <= 1) {
		throw ParseErrorException{ "Missing section name" };
	}
	else if (token.size() == 2 && token.back() == ':') {
		throw ParseErrorException{ "Missing section name" };
	}
		
	if (token.back() != ':') {
		throw ParseErrorException{ "Missing section delimiter ':'" };
	}

	assert(token.size() >= 3);
	m_name = token.substr(1, token.size() - 2);

	if (m_name != "chipsets" && m_name != "links") {
		throw ParseErrorException{ "Invalid section name '" + m_name + "'" };
	}
}
