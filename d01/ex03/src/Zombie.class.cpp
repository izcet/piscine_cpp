/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 14:44:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Zombie.class.hpp"

#define NUM_NAMES 16

Zombie::Zombie(void) {
	int		i;
	std::string	names[] = {"foo", "bar", "baz", "zom", "bie", "trent", "gwent",
		"The Cranberries", "Baul", "Lou", "Xavier Neil", "ft_zombie", "you",
		"BrainEater 9000", "Taserface", "Biezom"};

	i = rand() % NUM_NAMES;
	this->name = names[i];
	std::cout << "New Zombie '" << this->name << "'" << std::endl;
	return;
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "New Zombie '" << this->name << "'" << std::endl;
	return;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->name << " has died." << std::endl;
	return;
}

void	Zombie::announce(void) const
{
	std::cout << "Zombie '" << this->name << "': Why hello there. may I ";
	std::cout << "eat your brains?" << std::endl;
}

