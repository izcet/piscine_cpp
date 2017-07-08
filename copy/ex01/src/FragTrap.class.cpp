/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:25:13 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:24:57 by irhett           ###   ########.fr       */
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

std::ostream	&operator<<(std::ostream &o, FragTrap const &c)
{
	o << "{" << c.getName() << ":" << c.getHP() << ":" << c.getHPMax();
	o << ":" << c.getEP() << ":" << c.getEPMax() << ":" << c.getLevel();
	o << ":" << c.getMelee() << ":" << c.getRange() << ":";
	o << c.getArmor() << "}";
	return (o);
}

int				FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP [" << this->_name << "] attacks ";
	std::cout << target << " at range, causing " << this->_dmg_range;
	std::cout << " points of damange!" << std::endl;
	return (this->_dmg_range);
}

int				FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP [" << this->_name << "] attacks ";
	std::cout << target << " in melee, causing " << this->_dmg_range;
	std::cout << " points of damange!" << std::endl;
	return (this->_dmg_melee);
}

int				FragTrap::takeDamage(unsigned int amount)
{
	int		taken;

	taken = amount - this->_dr;
	if (taken < 0)
		taken = 0;
	this->_hp -= taken;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "FR4G-TP [" << this->_name << "] took ";
	std::cout << taken << "(" << amount << " - " << this->_dr << ")";
	std::cout << " points of damage! (HP=" << this->_hp << ")";
	std::cout << std::endl;
	return (this->_hp);
}

int				FragTrap::beRepaired(unsigned int amount)
{
	if ((int)amount + this->_hp > this->_hp_max)
	{
		this->_hp = this->_hp_max;
		amount -= this->_hp_max - this->_hp;
	}
	else
		this->_hp += amount;
	std::cout << "FR4G-TP [" << this->_name << "] was repaired ";
	std::cout << amount << " points! (HP=" << this->_hp << ")";
	std::cout << std::endl;
	return (this->_hp);
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

std::string		FragTrap::getName(void) const
{
	return (this->_name);
}

int				FragTrap::getHP(void) const
{
	return (this->_hp);
}

int				FragTrap::getHPMax(void) const
{
	return (this->_hp_max);
}

int				FragTrap::getEP(void) const
{
	return (this->_ep);
}

int				FragTrap::getEPMax(void) const
{
	return (this->_ep_max);
}

int				FragTrap::getLevel(void) const
{
	return (this->_level);
}

int				FragTrap::getMelee(void) const
{
	return (this->_dmg_melee);
}

int				FragTrap::getRange(void) const
{
	return (this->_dmg_range);
}

int				FragTrap::getArmor(void) const
{
	return (this->_dr);
}
