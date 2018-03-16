/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4071.hpp
*/

#pragma once

#include <string>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class C4071 final : public IComponent
	{
	public:
		C4071(std::string const &value);
		~C4071() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		PinMap m_pins;
	};
}
