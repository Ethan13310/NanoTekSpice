/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         False.hpp
*/

#pragma once

#include <string>

#include "Components/Inputs/Input.hpp"

namespace nts
{
	class False final : public Input
	{
	public:
		False();
		~False() = default;

		void dump() const override;
		void setValue(Tristate value) override;
	};
}
