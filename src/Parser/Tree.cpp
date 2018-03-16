/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Parser.cpp
*/

#include <cassert>
#include <string>
#include <vector>

#include "Exceptions.hpp"
#include "Parser.hpp"

nts::Tree::Tree(int argc, char const **argv) :
	m_args{ argc, argv }
{
	FileLoader file{ m_args.filepath() };
	std::string line;

	while (file.nextLine(line)) {
		Lexer const lexer{ line };
		
		if (lexer.count() > 0) {
			m_tree.push_back(initializeNode(lexer));
		}

		++m_line;
	}

	validateTree();
	initializeAllInputs();
}

std::vector<nts::Tree::Node> const &nts::Tree::get() const
{
	return m_tree;
}

nts::Tree::Node nts::Tree::initializeNode(Lexer const &line)
{
	assert(line.count() > 0);

	Node node;

	try {
		if (!parseSection(node, line)) {
			if (m_section == "chipsets") {
				parseChipset(node, line);
			}
			else {
				parseLink(node, line);
			}
		}
	}
	catch (ParseErrorException &e) {
		e.append(", at line " + std::to_string(m_line) + ".");
		throw e;
	}

	return node;
}

bool nts::Tree::parseSection(Node &node, Lexer const &line)
{
	assert(line.count() > 0);
	
	if (line.count() > 1 || line.token(0).front() != '.') {
		if (m_section.empty()) {
			throw ParseErrorException{ "Unexpected token (no previous section declaration)" };
		}

		return false;
	}

	Section const section{ line };

	m_section = section.name();
	section.initializeNode(node);

	return true;
}

void nts::Tree::parseChipset(Node &node, Lexer const &line)
{
	assert(line.count() > 0);

	Chipset const chipset{ line };
	chipset.initializeNode(node);
}

void nts::Tree::parseLink(Node &node, Lexer const &line)
{
	assert(line.count() > 0);

	Link const link{ line };
	link.initializeNode(node);
}

void nts::Tree::validateTree() const
{
	if (m_tree.size() == 0) {
		throw ParseErrorException{ "File is empty." };
	}

	std::size_t components{ 0 };
	std::size_t links{ 0 };

	for (auto const &node : m_tree)
	{
		if (node.type == Node::Type::Component) {
			++components;
		}
		else if (node.type == Node::Type::Link) {
			++links;
		}
	}

	if (components == 0) {
		throw ParseErrorException{ "'.chipsets' section is missing or empty." };
	}
	else if (links == 0) {
		throw ParseErrorException{ "'.links' section is missing or empty." };
	}
}

void nts::Tree::initializeAllInputs()
{
	for (auto &node : m_tree) {
		if (node.type == Node::Type::Component) {
			initializeInput(node);
		}
	}
}

void nts::Tree::initializeInput(Node &node)
{
	Chipset chipset{ node.name };

	if (chipset.type() == "input" || chipset.type() == "clock") {
		try {
			auto const pin{ chipset.name() };
			node.value = m_args.findInput(pin).value;
		}
		catch (InputErrorException const &) {
			// Nothing to do
		}
	}
}
