/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4013.hpp
*/

#pragma once

#include <array>
#include <string>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class C4013 final : public IComponent
	{
	public:
		C4013(std::string const &value);
		~C4013() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		Tristate computePin(std::size_t pin);
		void nextState(std::size_t i);

		void resetData();
		Tristate computeOutput(std::size_t i);
		Tristate applyNot(std::size_t i, Tristate state);

		PinMap m_pins;
		std::array<Tristate, 2> m_lastClockState;
		std::array<Tristate, 2> m_clockState;
		std::array<Tristate, 2> m_state;
		bool m_computed;
	};
}
