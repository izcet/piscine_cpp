/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 14:45:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ZombieHorde.class.hpp"
#include "Zombie.class.hpp"

int		main(void)
{
	ZombieHorde	z(5);

	std::cout << std::endl;
	z.announce();
	std::cout << std::endl;
	return (0);
}
