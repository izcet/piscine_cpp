/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:34:43 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 23:09:39 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void) {
	return;
}

const std::string	Weapon::getType(void) const
{
	return (this->_type);
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
}
