/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Link.hpp
*/

#include <algorithm>
#include <cassert>
#include <cctype>
#include <string>

#include "Exceptions.hpp"
#include "Parser.hpp"

nts::Link::Link(Lexer const &line)
{
	if (line.count() == 2) {
		parse(line.token(0), line.token(1));
	}
	else if (line.count() < 2) {
		throw ParseErrorException{ "Missing chipset link (expected 2 tokens, got 1)" };
	}
	else {
		auto const count{ std::to_string(line.count()) };
		throw ParseErrorException{ "Unexpected token (expected 2 tokens, got " + count + ")" };
	}
}

nts::Link::Link(std::string const &line) :
	Link{ Lexer{ line } }
{}

nts::Link::Pair const &nts::Link::first() const
{
	return m_first;
}

nts::Link::Pair const &nts::Link::second() const
{
	return m_second;
}

void nts::Link::initializeNode(Tree::Node &node) const
{
	node.type = Tree::Node::Type::Link;
	node.name = m_firstLink + " " + m_secondLink;
	node.value.clear();
}

void nts::Link::parse(std::string const &first, std::string const &second)
{
	validate(first);
	validate(second);

	m_firstLink = first;
	m_secondLink = second;

	m_first = split(m_firstLink);
	m_second = split(m_secondLink);
}

void nts::Link::validate(std::string const &link) const
{
	auto const delimiter{ link.find(':') };

	if (delimiter != link.find_last_of(':')) {
		throw ParseErrorException{ "Unexpected token ':'" };
	}

	if (delimiter == 0) {
		throw ParseErrorException{ "Expected chipset name before token ':'" };
	}

	auto const pin{ link.substr(delimiter + 1, link.size() - delimiter - 1) };

	if (pin.size() == 0) {
		throw ParseErrorException{ "Expected pin number after token ':'" };
	}

	auto const isNumber{ std::all_of(pin.begin(), pin.end(), [](char c) {
		return std::isdigit(c);
	}) };

	if (!isNumber) {
		throw ParseErrorException{ "Pin must be an integer (after token ':')" };
	}
}

nts::Link::Pair nts::Link::split(std::string const &link) const
{
	auto const delimiter{ link.find(':') };

	assert(delimiter != std::string::npos);

	auto const name{ link.substr(0, delimiter) };
	auto const pin{ link.substr(delimiter + 1, link.size() - delimiter - 1) };

	return { name, static_cast<std::size_t>(std::stoi(pin)) };
}
