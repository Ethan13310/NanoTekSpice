/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         String.hpp
*/

#pragma once

#include <functional>
#include <string>

#include "Components/IComponent.hpp"

namespace utils
{
	std::string &ltrim(std::string &str);
	std::string &rtrim(std::string &str);
	std::string &trim(std::string &str);

	std::string toString(nts::Tristate value);
	std::string toString(std::reference_wrapper<nts::IComponent> const component, std::size_t pin);

	std::string addr(void const *address);
}
