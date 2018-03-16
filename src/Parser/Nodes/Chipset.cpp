/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Chipset.hpp
*/

#include <cassert>
#include <string>

#include "Exceptions.hpp"
#include "Parser.hpp"

nts::Chipset::Chipset(Lexer const &line)
{
	if (line.count() == 2) {
		parse(line.token(0), line.token(1));
	}
	else if (line.count() < 2) {
		throw ParseErrorException{ "Missing chipset name" };
	}
	else {
		auto const count{ std::to_string(line.count()) };
		throw ParseErrorException{ "Unexpected token (expected 2 tokens, got " + count + ")" };
	}
}

nts::Chipset::Chipset(std::string const &line) :
	Chipset{ Lexer{ line } }
{}

std::string const &nts::Chipset::type() const
{
	return m_type;
}

std::string const &nts::Chipset::name() const
{
	return m_name;
}

std::string const &nts::Chipset::value() const
{
	return m_value;
}

void nts::Chipset::initializeNode(Tree::Node &node) const
{
	node.type = Tree::Node::Type::Component;
	node.name = m_fullName;
	node.value = m_value;
}

void nts::Chipset::parse(std::string const &chipset, std::string const &name)
{
	auto const left{ name.find('(') };

	if (left != std::string::npos) {
		parseWithValue(chipset, name, left);
	}
	else {
		if (name.find(')') != std::string::npos) {
			throw ParseErrorException{ "Unexpected token ')'" };
		}

		m_type = chipset;
		m_name = name;
		m_value.clear();
	}

	m_fullName = m_type + " " + m_name;

	checkForbiddenTokens(".:");
}

void nts::Chipset::parseWithValue(std::string const &chipset, std::string const &name, std::size_t left)
{
	auto const right{ name.find(')') };

	if (right == std::string::npos) {
		throw ParseErrorException{ "Expected token ')'" };
	}
	else if (right != name.find_last_of(')')) {
		throw ParseErrorException{ "Unexpected token ')'" };
	}
	else if (name.back() != ')') {
		throw ParseErrorException{ "Unexpected token after token ')'" };
	}

	m_type = chipset;
	m_name = name.substr(0, left);
	m_value = name.substr(left + 1, name.size() - left - 2);

	if (m_name.size() == 0) {
		throw ParseErrorException{ "Expected chipset name before token '('" };
	}
}

void nts::Chipset::checkForbiddenTokens(std::string const &forbidden) const
{
	for (auto const c : forbidden) {
		if (m_fullName.find(c) != std::string::npos) {
			throw ParseErrorException{ "Unexpected token '" + std::string{ c } + "'" };
		}
	}
}
