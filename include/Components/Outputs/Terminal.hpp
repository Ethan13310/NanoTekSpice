/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Terminal.hpp
*/

#pragma once

#include <string>

#include "Components/Outputs/Output.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class Terminal final : public Output
	{
	public:
		Terminal();
		~Terminal() = default;

		Tristate compute(std::size_t pin = 1) override;
		void dump() const override;

		void display() const override;
		void display(std::string const &name) const override;

	private:
		void computeData();

		char m_data{ 0 };
		bool m_displayable{ false };
		bool m_computed{ false };
	};
}
