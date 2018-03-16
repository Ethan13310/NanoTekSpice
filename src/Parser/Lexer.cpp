/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Lexer.cpp
*/

#include <algorithm>
#include <cassert>
#include <cctype>
#include <locale>
#include <string>
#include <sstream>
#include <vector>

#include "Parser.hpp"

nts::Lexer::Lexer(std::string const &line) :
	m_data{ line }
{
	removeComment();
	purgeSpaces();
	tokenize();
}

std::string const &nts::Lexer::token(std::size_t index) const
{
	assert(index < m_tokens.size());
	assert(m_tokens[index].size() > 0);

	return m_tokens[index];
}

std::size_t nts::Lexer::count() const
{
	return m_tokens.size();
}

void nts::Lexer::purgeSpaces()
{
	std::transform(m_data.begin(), m_data.end(), m_data.begin(), [](char c) {
		return (std::isspace<char>(c, std::locale::classic())) ? ' ' : c;
	});
}

void nts::Lexer::removeComment()
{
	auto it{ std::find_if(m_data.begin(), m_data.end(), [](char c) {
		return c == '#';
	}) };

	m_data.erase(it, m_data.end());
}

void nts::Lexer::tokenize()
{
	m_tokens.clear();

	std::stringstream ss{ m_data };
	std::string token;

	while (std::getline(ss, token, ' ')) {
		if (token.size() > 0) {
			m_tokens.push_back(token);
		}
	}
}
