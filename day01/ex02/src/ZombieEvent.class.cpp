/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 15:27:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ZombieEvent.class.hpp"

ZombieEvent::ZombieEvent(void) {
	std::cout << "New Zombie Event!" << std::endl;
	return;
}

ZombieEvent::~ZombieEvent(void) {
	std::cout << "Zombie Event has ended." << std::endl;
	return;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie	*z;

	z = new Zombie(name);
	z->setType(this->type);
	z->announce();
	return (z);
}

Zombie	*ZombieEvent::randomChump(void)
{
	Zombie	*z;

	z = new Zombie();
	z->setType(this->type);
	z->announce();
	return (z);
}
