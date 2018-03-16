/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         Gates.hpp
*/

#include "Components/Gates.hpp"

/**
 * AND Logic Gate
 * Truth table :
 * +-------------+
 * |  A   B  OUT |
 * +-------------+
 * |  0   0   0  |
 * |  0   1   0  |
 * |  0   ?   0  |
 * |  1   0   0  |
 * |  1   1   1  |
 * |  1   ?   ?  |
 * |  ?   0   0  |
 * |  ?   1   ?  |
 * |  ?   ?   ?  |
 * +-------------+
 */

nts::Tristate gate::And(nts::Tristate lhs, nts::Tristate rhs)
{
	if (lhs == nts::Tristate::True && rhs == nts::Tristate::True) {
		return nts::Tristate::True;
	}
	else if (lhs == nts::Tristate::False || rhs == nts::Tristate::False) {
		return nts::Tristate::False;
	}
	return nts::Tristate::Undefined;
}

/**
 * NAND Logic Gate
 * Truth table :
 * +-------------+
 * |  A   B  OUT |
 * +-------------+
 * |  0   0   1  |
 * |  0   1   1  |
 * |  0   ?   1  |
 * |  1   0   1  |
 * |  1   1   0  |
 * |  1   ?   ?  |
 * |  ?   0   1  |
 * |  ?   1   ?  |
 * |  ?   ?   ?  |
 * +-------------+
 */

nts::Tristate gate::Nand(nts::Tristate lhs, nts::Tristate rhs)
{
	return Not(And(lhs, rhs));
}

/**
 * OR Logic Gate
 * Truth table :
 * +-------------+
 * |  A   B  OUT |
 * +-------------+
 * |  0   0   0  |
 * |  0   1   1  |
 * |  0   ?   ?  |
 * |  1   0   1  |
 * |  1   1   1  |
 * |  1   ?   1  |
 * |  ?   0   ?  |
 * |  ?   1   1  |
 * |  ?   ?   ?  |
 * +-------------+
 */

nts::Tristate gate::Or(nts::Tristate lhs, nts::Tristate rhs)
{
	if (lhs == nts::Tristate::True || rhs == nts::Tristate::True) {
		return nts::Tristate::True;
	}
	else if (lhs == nts::Tristate::Undefined || rhs == nts::Tristate::Undefined) {
		return nts::Tristate::Undefined;
	}
	return nts::Tristate::False;
}

/**
 * NOR Logic Gate
 * Truth table :
 * +-------------+
 * |  A   B  OUT |
 * +-------------+
 * |  0   0   1  |
 * |  0   1   0  |
 * |  0   ?   ?  |
 * |  1   0   0  |
 * |  1   1   0  |
 * |  1   ?   0  |
 * |  ?   0   ?  |
 * |  ?   1   0  |
 * |  ?   ?   ?  |
 * +-------------+
 */

nts::Tristate gate::Nor(nts::Tristate lhs, nts::Tristate rhs)
{
	return Not(Or(lhs, rhs));
}

/**
 * XOR Logic Gate
 * Truth table :
 * +-------------+
 * |  A   B  OUT |
 * +-------------+
 * |  0   0   0  |
 * |  0   1   1  |
 * |  0   ?   ?  |
 * |  1   0   1  |
 * |  1   1   0  |
 * |  1   ?   ?  |
 * |  ?   0   ?  |
 * |  ?   1   ?  |
 * |  ?   ?   ?  |
 * +-------------+
 */

nts::Tristate gate::Xor(nts::Tristate lhs, nts::Tristate rhs)
{
	if (lhs == nts::Tristate::Undefined || rhs == nts::Tristate::Undefined) {
		return nts::Tristate::Undefined;
	}
	else if (lhs != rhs) {
		return nts::Tristate::True;
	}
	return nts::Tristate::False;
}

/**
 * XNOR Logic Gate
 * Truth table :
 * +-------------+
 * |  A   B  OUT |
 * +-------------+
 * |  0   0   1  |
 * |  0   1   0  |
 * |  0   ?   ?  |
 * |  1   0   0  |
 * |  1   1   1  |
 * |  1   ?   ?  |
 * |  ?   0   ?  |
 * |  ?   1   ?  |
 * |  ?   ?   ?  |
 * +-------------+
 */

nts::Tristate gate::Xnor(nts::Tristate lhs, nts::Tristate rhs)
{
	return Not(Xor(lhs, rhs));
}

/**
 * NOT Logic Gate
 * Truth table :
 * +---------+
 * |  A  OUT |
 * +---------+
 * |  0   1  |
 * |  1   0  |
 * |  ?   ?  |
 * +---------+
 */

nts::Tristate gate::Not(nts::Tristate value)
{
	if (value == nts::Tristate::True) {
		return nts::Tristate::False;
	}
	else if (value == nts::Tristate::False) {
		return nts::Tristate::True;
	}
	return nts::Tristate::Undefined;
}
