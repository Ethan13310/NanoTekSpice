/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Builtin.hpp
*/

#pragma once

#include <functional>
#include <string>
#include <unordered_map>

#include "Circuit/Circuit.hpp"

namespace nts
{
	class Builtin
	{
	public:
		Builtin();
		~Builtin() = default;

		Builtin(Builtin const &) = delete;
		Builtin(Builtin &&) = default;

		Builtin &operator=(Builtin const &) = delete;
		Builtin &operator=(Builtin &&) = default;

		bool operator()(Circuit &circuit, std::string const &cmd) const;

	private:
		using Func = std::function<void(Circuit &)>;
		std::unordered_map<std::string, Func> m_commands;
	};
}
