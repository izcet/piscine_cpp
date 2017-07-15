/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 12:55:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ZombieEvent.class.hpp"
#include "Zombie.class.hpp"

int		main(void)
{
	Zombie		*z;
	ZombieEvent	ze;

	z = new Zombie("Wizzle");
	z->announce();
	delete z;

	ze.setZombieType("Ice");
	z = ze.newZombie("Wizzle 2.0");
	delete z;
	z = ze.randomChump();
	delete z;
	return (0);
}
