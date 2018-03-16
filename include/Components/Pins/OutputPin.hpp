/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         OutputPin.hpp
*/

#pragma once

#include "Components/IComponent.hpp"
#include "Components/Pins/Pin.hpp"

namespace nts
{
	class OutputPin final : public Pin
	{
	public:
		OutputPin(IComponent *component, std::size_t pin);
		~OutputPin() = default;

		void link(IComponent &other, std::size_t otherPin) override;
		Tristate compute() override;
		void reset() override;
	};
}
