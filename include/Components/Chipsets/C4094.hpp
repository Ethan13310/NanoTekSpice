/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4094.hpp
*/

#pragma once

#include <array>
#include <string>
#include <unordered_map>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class C4094 final : public IComponent
	{
	public:
		C4094(std::string const &value);
		~C4094() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		void computeOutput();
		void shift();
		void nextState();

		PinMap m_pins;
		std::unordered_map<std::size_t, std::size_t> m_pinToBit;
		std::array<Tristate, 8> m_bits;
		Tristate m_lastClockState;
		Tristate m_clockState;
		Tristate m_qs;
		Tristate m_qsp;
		bool m_computed;
	};
}
