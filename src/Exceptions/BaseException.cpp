/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         BaseException.cpp
*/

#include <string>

#include "Exceptions.hpp"

nts::BaseException::BaseException(char const *message) :
	m_message{ message }
{}

nts::BaseException::BaseException(std::string const &message) :
	m_message{ message }
{}

void nts::BaseException::update(char const *message)
{
	m_message = message;
}

void nts::BaseException::update(std::string const &message)
{
	m_message = message;
}

void nts::BaseException::append(char const *message)
{
	m_message += message;
}

void nts::BaseException::append(std::string const &message)
{
	m_message += message;
}

char const *nts::BaseException::what() const noexcept
{
	return m_message.c_str();
}
