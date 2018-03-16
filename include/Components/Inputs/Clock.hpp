/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Clock.hpp
*/

#pragma once

#include <string>

#include "Components/Inputs/Input.hpp"

namespace nts
{
	class Clock final : public Input
	{
	public:
		Clock(std::string const &value);
		~Clock() = default;

		void dump() const override;
		void setValue(Tristate value) override;
		void reverse();
	};
}
