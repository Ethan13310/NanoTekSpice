/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         InputPin.hpp
*/

#pragma once

#include "Components/IComponent.hpp"
#include "Components/Pins/Pin.hpp"

namespace nts
{
	class InputPin final : public Pin
	{
	public:
		InputPin(IComponent *component, std::size_t pin);
		~InputPin() = default;

		void link(IComponent &other, std::size_t otherPin) override;
		Tristate compute() override;
		void reset() override;

	private:
		Tristate m_state;
		bool m_computed;
	};
}
