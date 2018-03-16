/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         IComponent.hpp
*/

#pragma once

#include <array>
#include <map>
#include <utility>

namespace nts
{
	enum class Tristate
	{
		Undefined,
		True,
		False
	};

	class IComponent
	{
	public:
		IComponent() = default;
		virtual ~IComponent() = default;

		IComponent(IComponent const &) = delete;
		IComponent(IComponent &&) = default;

		IComponent &operator=(IComponent const &) = delete;
		IComponent &operator=(IComponent &&) = default;

		virtual Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	};
}

std::ostream &operator<<(std::ostream &out, nts::Tristate state);
