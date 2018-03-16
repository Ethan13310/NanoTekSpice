/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         C4514.hpp
*/

#pragma once

#include <array>
#include <string>
#include <unordered_map>

#include "Components/IComponent.hpp"
#include "Components/Pins/PinMap.hpp"

namespace nts
{
	class C4514 final : public IComponent
	{
	public:
		using DataArray = std::array<Tristate, 4>;

		C4514(std::string const &value);
		~C4514() = default;

		Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		void saveData();
		Tristate computeOutput(std::size_t pin);
		std::size_t selectOutput() const;
		bool isTrue(DataArray const &out) const;

		PinMap m_pins;
		std::unordered_map<std::size_t, DataArray> m_truthTable;
		DataArray m_data;
		bool m_computed;
	};
}
