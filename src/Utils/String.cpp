/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         String.cpp
*/

#include <algorithm>
#include <cctype>
#include <locale>
#include <sstream>
#include <string>

#include "Utils.hpp"

std::string &utils::ltrim(std::string &str)
{
	auto it{ std::find_if(str.begin(), str.end(), [](char c) {
		return !(std::isspace<char>(c, std::locale::classic()));
	}) };

	str.erase(str.begin(), it);
	return str;
}

std::string &utils::rtrim(std::string &str)
{
	auto it{ std::find_if(str.rbegin(), str.rend(), [](char c) {
		return !(std::isspace<char>(c, std::locale::classic()));
	}) };

	str.erase(it.base(), str.end());
	return str;
}

std::string &utils::trim(std::string &str)
{
	return ltrim(rtrim(str));
}

std::string utils::toString(nts::Tristate value)
{
	if (value == nts::Tristate::True) {
		return "1";
	}
	else if (value == nts::Tristate::False) {
		return "0";
	}
	else {
		return "U";
	}
}

std::string utils::toString(std::reference_wrapper<nts::IComponent> const component, std::size_t pin)
{
	return addr(&component.get()) + "[" + std::to_string(pin) + "]";
}

std::string utils::addr(void const *address)
{
	std::ostringstream ss;
	ss << address;
	return "<" + ss.str() + ">";
}
