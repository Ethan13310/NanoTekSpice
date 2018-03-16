/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Gates.hpp
*/

#include "Components/IComponent.hpp"

namespace gate
{
	nts::Tristate And(nts::Tristate lhs, nts::Tristate rhs);
	nts::Tristate Nand(nts::Tristate lhs, nts::Tristate rhs);
	nts::Tristate Or(nts::Tristate lhs, nts::Tristate rhs);
	nts::Tristate Nor(nts::Tristate lhs, nts::Tristate rhs);
	nts::Tristate Xor(nts::Tristate lhs, nts::Tristate rhs);
	nts::Tristate Xnor(nts::Tristate lhs, nts::Tristate rhs);
	nts::Tristate Not(nts::Tristate value);
}
