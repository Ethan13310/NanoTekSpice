/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4040.hpp
*/

#pragma once

#include <string>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class C4040 final : public IComponent
	{
	public:
		C4040(std::string const &value);
		~C4040() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		void nextState();

		Tristate bit(std::size_t i) const;
		void increment();
		void reset();

		PinMap m_pins;
		std::unordered_map<std::size_t, std::size_t> m_pinToBit;
		std::uint16_t m_counter;
		Tristate m_lastClockState;
		bool m_computed;
	};
}
