/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:25:13 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:45:11 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "FragTrap.class.hpp"

FragTrap::FragTrap(void) :
	_name("FUBAR"),
	_hp(0),
	_hp_max(0),
	_ep(0),
	_ep_max(0),
	_level(0),
	_dmg_melee(0),
	_dmg_range(0),
	_dr(0)
{
	std::cout << "[FragTrap Default Should not be called!]" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : 
	_name(name),
	_hp(100),
	_hp_max(100),
	_ep(100),
	_ep_max(100),
	_level(1),
	_dmg_melee(30),
	_dmg_range(20),
	_dr(5)
{
	std::cout << "(FragTrap Parametric Constructor: " << this->_name;
	std::cout << ")" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &old) :
	_name(old.getName()),
	_hp(old.getHP()),
	_hp_max(old.getHPMax()),
	_ep(old.getEP()),
	_ep_max(old.getEPMax()),
	_level(old.getLevel()),
	_dmg_melee(old.getMelee()),
	_dmg_range(old.getRange()),
	_dr(old.getArmor())
{
	std::cout << "(FragTrap Copy Constructor: " << this->_name;
	std::cout << ")" << std::endl;
	*this = old;
	return;
}

FragTrap::~FragTrap(void) {
	std::cout << "(FragTrap Destructor: " << this->_name;
	std::cout << ")" << std::endl;
	return;
}

FragTrap		&FragTrap::operator=(FragTrap const &old)
{
	std::cout << "(FragTrap Assignment Operator: " << old.getName();
	std::cout << ")" << std::endl;
	if (this != &old)
	{
		this->_name = old.getName();
		this->_hp = old.getHP();
		this->_hp_max = old.getHPMax();
		this->_ep = old.getEP();
		this->_ep_max = old.getEPMax();
		this->_level = old.getLevel();
		this->_dmg_melee = old.getMelee();
		this->_dmg_range = old.getRange();
		this->_dr = old.getArmor();
	}
	return *this;
}
int				FragTrap::vaultHunterDotExe(std::string const &target)
{
	const char	*action[] = {"looks intimidatingly at ",
		"clips through a wall at ", "stabs a voodoo doll of ", "trips ",
		"laughs at ", "falls on "};
	int		i;
	int		dmg;

	i = rand() % 6;
	dmg = ((i % 2) * 10) + this->_dmg_range + 10;
	if ((this->_ep - 25) >= 0)
	{
		this->_ep -= 25;
		std::cout << "FR4G-TP [" << this->_name << "] " << action[i];
		std::cout << target << " dealing " << dmg << " points of damage! ";
		std::cout << "(EP=" << this->_ep << ")" << std::endl;
		return (dmg);
	}
	std::cout << "FR4G-TP [" << this->_name << "] exhausted (EP=";
	std::cout << this->_ep << ")" << std::endl;
	return (0);
}
