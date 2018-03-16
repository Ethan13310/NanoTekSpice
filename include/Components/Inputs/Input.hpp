/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Input.hpp
*/

#pragma once

#include <string>

#include "Components/IComponent.hpp"
#include "Components/Pins/OutputPin.hpp"

namespace nts
{
	class Input : public IComponent
	{
	public:
		Input(std::string const &value);
		~Input() = default;

		Tristate compute(std::size_t pin = 1) override final;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override final;
		void dump() const override;

		virtual Tristate value() const final;
		virtual void setValue(Tristate value);
		virtual void setValue(int value) final;
		virtual void setValue(std::string const &value) final;

	protected:
		Tristate m_value{ Tristate::Undefined };
		OutputPin m_pin;
	};
}
