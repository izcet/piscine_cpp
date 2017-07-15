/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 13:58:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Zombie.class.hpp"

#define NUM_NAMES 7

Zombie::Zombie(void) {
	int		seed;
	std::string	names[] = {"foo", "bar", "baz", "zom", "bie", "trent", "gwent"};

	srand(time(NULL));
	seed = rand();
	srand(seed);
	seed = rand() % NUM_NAMES;
	this->name = names[seed];
	return;
}

Zombie::Zombie(std::string name) {
	this->name = name;
	return;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->name << " has died." << std::endl;
	return;
}

void	Zombie::announce(void) const
{
	if (this->type.empty())
		std::cout << "A new Basic Zombie";
	else
		std::cout << "A new '" << this->type << "' Zombie";
	std::cout << " named '" << this->name << "' has arrived." << std::endl;
}

void	Zombie::setType(std::string newType)
{
	this->type = newType;
}
