/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:25:13 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:40:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap(void) :
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
	std::cout << "[ClapTrap Default Should not be called!]" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : 
	_name(name),
	_hp(100),
	_hp_max(100),
	_ep(50),
	_ep_max(50),
	_level(1),
	_dmg_melee(20),
	_dmg_range(15),
	_dr(3)
{
	std::cout << "(ClapTrap Parametric Constructor: " << this->_name;
	std::cout << ")" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &old) :
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
	std::cout << "(ClapTrap Copy Constructor: " << this->_name;
	std::cout << ")" << std::endl;
	*this = old;
	return;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "(ClapTrap Destructor: " << this->_name;
	std::cout << ")" << std::endl;
	return;
}

ClapTrap		&ClapTrap::operator=(ClapTrap const &old)
{
	std::cout << "(ClapTrap Assignment Operator: " << old.getName();
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

std::ostream	&operator<<(std::ostream &o, ClapTrap const &c)
{
	o << "{" << c.getName() << ":" << c.getHP() << ":" << c.getHPMax();
	o << ":" << c.getEP() << ":" << c.getEPMax() << ":" << c.getLevel();
	o << ":" << c.getMelee() << ":" << c.getRange() << ":";
	o << c.getArmor() << "}";
	return (o);
}

int				ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP [" << this->_name << "] attacks ";
	std::cout << target << " at range, causing " << this->_dmg_range;
	std::cout << " points of damange!" << std::endl;
	return (this->_dmg_range);
}

int				ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP [" << this->_name << "] attacks ";
	std::cout << target << " in melee, causing " << this->_dmg_range;
	std::cout << " points of damange!" << std::endl;
	return (this->_dmg_melee);
}

int				ClapTrap::takeDamage(unsigned int amount)
{
	int		taken;

	taken = amount - this->_dr;
	if (taken < 0)
		taken = 0;
	this->_hp -= taken;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "SC4V-TP [" << this->_name << "] took ";
	std::cout << taken << "(" << amount << " - " << this->_dr << ")";
	std::cout << " points of damage! (HP=" << this->_hp << ")";
	std::cout << std::endl;
	return (this->_hp);
}

int				ClapTrap::beRepaired(unsigned int amount)
{
	if ((int)amount + this->_hp > this->_hp_max)
	{
		this->_hp = this->_hp_max;
		amount -= this->_hp_max - this->_hp;
	}
	else
		this->_hp += amount;
	std::cout << "SC4V-TP [" << this->_name << "] was repaired ";
	std::cout << amount << " points! (HP=" << this->_hp << ")";
	std::cout << std::endl;
	return (this->_hp);
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

int				ClapTrap::getHP(void) const
{
	return (this->_hp);
}

int				ClapTrap::getHPMax(void) const
{
	return (this->_hp_max);
}

int				ClapTrap::getEP(void) const
{
	return (this->_ep);
}

int				ClapTrap::getEPMax(void) const
{
	return (this->_ep_max);
}

int				ClapTrap::getLevel(void) const
{
	return (this->_level);
}

int				ClapTrap::getMelee(void) const
{
	return (this->_dmg_melee);
}

int				ClapTrap::getRange(void) const
{
	return (this->_dmg_range);
}

int				ClapTrap::getArmor(void) const
{
	return (this->_dr);
}
