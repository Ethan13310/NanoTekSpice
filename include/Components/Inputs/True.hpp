/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         True.hpp
*/

#pragma once

#include <string>

#include "Components/Inputs/Input.hpp"

namespace nts
{
	class True final : public Input
	{
	public:
		True();
		~True() = default;

		void dump() const override;
		void setValue(Tristate value) override;
	};
}
