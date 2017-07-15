/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 23:12:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "HumanA.class.hpp"

HumanA::HumanA(std::string name, Weapon &wep) : _name(name), _wep(wep) {
	return;
}

HumanA::~HumanA(void) {
	return;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_wep.getType();
	std::cout << std::endl;
}
