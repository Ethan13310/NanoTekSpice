/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         ComponentFactory.cpp
*/

#include <string>

#include "Components.hpp"
#include "Exceptions.hpp"

nts::ComponentFactory::ComponentFactory()
{
	m_factories["4001"] = &ComponentFactory::create4001;
	m_factories["4008"] = &ComponentFactory::create4008;
	m_factories["4011"] = &ComponentFactory::create4011;
	m_factories["4013"] = &ComponentFactory::create4013;
	m_factories["4017"] = &ComponentFactory::create4017;
	m_factories["4030"] = &ComponentFactory::create4030;
	m_factories["4040"] = &ComponentFactory::create4040;
	m_factories["4069"] = &ComponentFactory::create4069;
	m_factories["4071"] = &ComponentFactory::create4071;
	m_factories["4081"] = &ComponentFactory::create4081;
	m_factories["4094"] = &ComponentFactory::create4094;
	m_factories["4514"] = &ComponentFactory::create4514;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(std::string const &type, std::string const &value) const
{
	auto it{ m_factories.find(type) };

	if (it != m_factories.end()) {
		return it->second(*this, value);
	}

	throw nts::UnknownComponentException{ type };
}

std::unique_ptr<nts::Input> nts::ComponentFactory::createInput(std::string const &value) const
{
	return std::make_unique<Input>(value);
}

std::unique_ptr<nts::Output> nts::ComponentFactory::createOutput() const
{
	return std::make_unique<Output>();
}

std::unique_ptr<nts::True> nts::ComponentFactory::createTrue() const
{
	return std::make_unique<True>();
}

std::unique_ptr<nts::False> nts::ComponentFactory::createFalse() const
{
	return std::make_unique<False>();
}

std::unique_ptr<nts::Clock> nts::ComponentFactory::createClock(std::string const &value) const
{
	return std::make_unique<Clock>(value);
}

std::unique_ptr<nts::Terminal> nts::ComponentFactory::createTerminal() const
{
	return std::make_unique<Terminal>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4001(std::string const &value) const
{
	return std::make_unique<C4001>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4008(std::string const &value) const
{
	return std::make_unique<C4008>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4011(std::string const &value) const
{
	return std::make_unique<C4011>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4013(std::string const &value) const
{
	return std::make_unique<C4013>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4017(std::string const &value) const
{
	return std::make_unique<C4017>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4030(std::string const &value) const
{
	return std::make_unique<C4030>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4040(std::string const &value) const
{
	return std::make_unique<C4040>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4069(std::string const &value) const
{
	return std::make_unique<C4069>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4071(std::string const &value) const
{
	return std::make_unique<C4071>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4081(std::string const &value) const
{
	return std::make_unique<C4081>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4094(std::string const &value) const
{
	return std::make_unique<C4094>(value);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4514(std::string const &value) const
{
	return std::make_unique<C4514>(value);
}
