/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Chipset.hpp
*/

#pragma once

#include <string>

#include "Components/IComponent.hpp"
#include "Parser/Lexer.hpp"
#include "Parser/Tree.hpp"

namespace nts
{
	class Chipset final
	{
	public:
		explicit Chipset(Lexer const &line);
		explicit Chipset(std::string const &line);

		~Chipset() = default;

		Chipset(Chipset const &) = default;
		Chipset(Chipset &&) = default;

		Chipset &operator=(Chipset const &) = default;
		Chipset &operator=(Chipset &&) = default;

		std::string const &type() const;
		std::string const &name() const;
		std::string const &value() const;

		void initializeNode(Tree::Node &node) const;

	private:
		void parse(std::string const &chipset, std::string const &name);
		void parseWithValue(std::string const &chipset, std::string const &name, std::size_t left);
		void checkForbiddenTokens(std::string const &forbidden) const;

		std::string m_type;
		std::string m_name;
		std::string m_fullName;
		std::string m_value;
	};
}
