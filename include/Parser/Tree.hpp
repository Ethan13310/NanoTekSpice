/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Parser.hpp
*/

#pragma once

#include <string>
#include <vector>

#include "Parser/Arguments.hpp"
#include "Parser/Lexer.hpp"

namespace nts
{
	class Tree
	{
	public:
		struct Node
		{
			enum class Type
			{
				Section,
				Component,
				Link
			};

			Type type;
			std::string name;
			std::string value;
		};		

		Tree(int argc, char const **argv);
		~Tree() = default;

		Tree(Tree const &) = delete;
		Tree(Tree &&) = default;

		Tree &operator=(Tree const &) = delete;
		Tree &operator=(Tree &&) = default;

		std::vector<Node> const &get() const;

	private:
		Node initializeNode(Lexer const &line);

		bool parseSection(Node &node, Lexer const &line);
		void parseChipset(Node &node, Lexer const &line);
		void parseLink(Node &node, Lexer const &line);

		void validateTree() const;
		void initializeAllInputs();
		void initializeInput(Node &node);

		Arguments m_args;
		std::vector<Node> m_tree;

		std::size_t m_line{ 1 };
		std::string m_section;
	};
}
