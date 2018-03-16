/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Executor.hpp
*/

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>

#include "Components.hpp"
#include "Parser/Tree.hpp"
#include "Parser/Nodes/Chipset.hpp"

namespace nts
{
	class Executor
	{
	public:
		Executor(Tree const &tree);
		~Executor() = default;

		Executor(Executor const &) = delete;
		Executor(Executor &&) = default;

		Executor &operator=(Executor const &) = delete;
		Executor &operator=(Executor &&) = default;

		void display() const;
		void simulate();
		void dump() const;
		void reverseClocks();
		void updateInput(InputValue const &input);
		void resetComputeState();

	private:
		using CreateFunc = std::function<void(Executor &, Chipset const &)>;

		void createComponent(Tree::Node const &node);
		void createLink(Tree::Node const &node);

		void createInput(Chipset const &chipset);
		void createOutput(Chipset const &chipset);
		void createTrue(Chipset const &chipset);
		void createFalse(Chipset const &chipset);
		void createClock(Chipset const &chipset);
		void createTerminal(Chipset const &chipset);

		nts::ComponentFactory m_factory;
		
		std::map<std::string, std::weak_ptr<nts::Output>> m_outputs;
		std::unordered_map<std::string, std::weak_ptr<nts::Input>> m_inputs;
		std::unordered_map<std::string, std::weak_ptr<nts::Clock>> m_clocks;
		std::map<std::string, std::shared_ptr<nts::IComponent>> m_components;
	};
}
