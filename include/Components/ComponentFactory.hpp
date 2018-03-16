/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         ComponentFactory.hpp
*/

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "Components/IComponent.hpp"
#include "Components/Inputs/Clock.hpp"
#include "Components/Inputs/False.hpp"
#include "Components/Inputs/Input.hpp"
#include "Components/Inputs/True.hpp"
#include "Components/Outputs/Output.hpp"
#include "Components/Outputs/Terminal.hpp"

namespace nts
{
	class ComponentFactory
	{
	public:
		ComponentFactory();
		~ComponentFactory() = default;

		ComponentFactory(ComponentFactory const &) = delete;
		ComponentFactory(ComponentFactory &&) = default;

		ComponentFactory &operator=(ComponentFactory const &) = delete;
		ComponentFactory &operator=(ComponentFactory &&) = default;

		std::unique_ptr<IComponent> createComponent(std::string const &type, std::string const &value) const;

		std::unique_ptr<Input> createInput(std::string const &value) const;
		std::unique_ptr<Output> createOutput() const;
		std::unique_ptr<True> createTrue() const;
		std::unique_ptr<False> createFalse() const;
		std::unique_ptr<Clock> createClock(std::string const &value) const;
		std::unique_ptr<Terminal> createTerminal() const;

	private:
		std::unique_ptr<IComponent> create4001(std::string const &value) const;
		std::unique_ptr<IComponent> create4008(std::string const &value) const;
		std::unique_ptr<IComponent> create4011(std::string const &value) const;
		std::unique_ptr<IComponent> create4013(std::string const &value) const;
		std::unique_ptr<IComponent> create4017(std::string const &value) const;
		std::unique_ptr<IComponent> create4030(std::string const &value) const;
		std::unique_ptr<IComponent> create4040(std::string const &value) const;
		std::unique_ptr<IComponent> create4069(std::string const &value) const;
		std::unique_ptr<IComponent> create4071(std::string const &value) const;
		std::unique_ptr<IComponent> create4081(std::string const &value) const;
		std::unique_ptr<IComponent> create4094(std::string const &value) const;
		std::unique_ptr<IComponent> create4514(std::string const &value) const;

		using Func = std::function<std::unique_ptr<IComponent>(ComponentFactory const &, std::string const &)>;
		std::unordered_map<std::string, Func> m_factories;
	};
}
