/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 14:46:29 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ZombieHorde.class.hpp"

ZombieHorde::ZombieHorde(int n) : _num(n) {
	int		i;

	srand(time(NULL));
	std::cout << "<--- New Zombie Horde! --->" << std::endl;
	this->_zoms = new Zombie*[n];
	i = 0;
	while (i < n)
		this->_zoms[i++] = new Zombie();

	return;
}

ZombieHorde::~ZombieHorde(void) {
	int		i;

	i = 0;
	while (i < this->_num)
		delete this->_zoms[i++];
	delete this->_zoms;
	std::cout << "<--- Zombie Horde has ended. --->" << std::endl;
	return;
}

void	ZombieHorde::announce(void) const
{
	int		i;

	i = 0;
	while (i < this->_num)
		this->_zoms[i++]->announce();
}
