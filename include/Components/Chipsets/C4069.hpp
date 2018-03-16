/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4069.hpp
*/

#pragma once

#include <string>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class C4069 final : public IComponent
	{
	public:
		C4069(std::string const &value);
		~C4069() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		PinMap m_pins;
	};
}
