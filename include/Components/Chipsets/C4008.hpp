/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4008.hpp
*/

#pragma once

#include <string>
#include <utility>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class C4008 final : public IComponent
	{
	public:
		using SumResult = std::pair<Tristate, Tristate>;

		C4008(std::string const &value);
		~C4008() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		Tristate computeCO();
		SumResult computeS4();
		SumResult computeS3();
		SumResult computeS2();
		SumResult computeS1();

		Tristate sum(Tristate a, Tristate b, Tristate &carry) const;

		PinMap m_pins;
	};
}
