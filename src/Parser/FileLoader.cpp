/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         FileLoader.cpp
*/

#include <fstream>
#include <sstream>
#include <string>

#include "Exceptions.hpp"
#include "Parser.hpp"

nts::FileLoader::FileLoader(std::string const &filepath)
{
	std::ifstream file{ filepath };

	if (!file.is_open()) {
		throw IOException{ filepath + ": Cannot open file." };
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	m_data = buffer.str();
	m_stream = std::stringstream{ m_data };
}

bool nts::FileLoader::nextLine(std::string &line)
{
	if (!std::getline(m_stream, line)) {
		return false;
	}

	return true;
}

void nts::FileLoader::reset()
{
	m_stream.seekg(0);
}
