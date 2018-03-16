/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Pin.hpp
*/

#pragma once

#include <functional>
#include <utility>
#include <vector>

#include "Components/IComponent.hpp"

namespace nts
{
	class Pin
	{
	public:
		using Link = std::pair<std::reference_wrapper<IComponent>, std::size_t>;

		Pin(IComponent *component, std::size_t id);
		~Pin() = default;

		Pin(Pin const &) = delete;
		Pin(Pin &&) = default;

		Pin &operator=(Pin const &) = delete;
		Pin &operator=(Pin &&) = default;

		virtual void link(IComponent &other, std::size_t otherPin) = 0;
		virtual Tristate compute() = 0;
		virtual void reset() = 0;

		bool isLinked() const;
		bool isSelf(IComponent &other, std::size_t otherPin) const;
		bool linkExists(IComponent &other, std::size_t otherPin) const;
		void dump() const;

	protected:
		IComponent &m_component;
		std::size_t m_pin;
		std::vector<Link> m_links;
	};
}
