/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         PinMap.hpp
*/

#pragma once

#include <functional>
#include <map>
#include <memory>

#include "Components/IComponent.hpp"
#include "Components/Pins/Pin.hpp"

namespace nts
{
	class PinMap
	{
	public:
		using OneInputGateFunc = std::function<Tristate(Tristate)>;
		using TwoInputsGateFunc = std::function<Tristate(Tristate, Tristate)>;

		PinMap() = default;
		~PinMap() = default;

		PinMap(PinMap const &) = delete;
		PinMap(PinMap &&) = default;

		PinMap &operator=(PinMap const &) = delete;
		PinMap &operator=(PinMap &&) = default;

		void addInput(IComponent *component, std::size_t pin);
		void addOutput(IComponent *component, std::size_t pin);
		void addInputRange(IComponent *component, std::size_t start, std::size_t end);
		void addOutputRange(IComponent *component, std::size_t start, std::size_t end);

		Tristate compute(std::size_t pin);
		Tristate compute(TwoInputsGateFunc gate, std::size_t pinA, std::size_t pinB);
		Tristate compute(OneInputGateFunc gate, std::size_t pin);

		void link(std::size_t pin, IComponent &other, std::size_t otherPin);
		bool isLinked(std::size_t pin) const;

		void reset();
		void dump() const;

	private:
		void assertExists(std::size_t pin) const;

		std::map<std::size_t, std::unique_ptr<Pin>> m_pins;
	};
}
