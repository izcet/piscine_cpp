/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 23:13:21 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "HumanB.class.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	return;
}

HumanB::~HumanB(void) {
	return;
}

void	HumanB::setWeapon(Weapon &wep)
{
	this->_wep = &wep;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_wep->getType();
	std::cout << std::endl;
}
