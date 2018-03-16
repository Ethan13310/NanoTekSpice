/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Output.hpp
*/

#pragma once

#include <string>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class Output : public IComponent
	{
	public:
		Output();
		~Output() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

		virtual void display() const;
		virtual void display(std::string const &name) const;

	protected:
		Tristate m_value{ Tristate::Undefined };
		PinMap m_pins;
	};
}
