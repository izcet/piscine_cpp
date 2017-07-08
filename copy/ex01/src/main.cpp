/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:35:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ScavTrap.class.hpp"

int		main(void)
{
	ScavTrap	ska("Frank");

	ska.rangedAttack("Bar");
	ska.takeDamage(10);
	ska.meleeAttack("Bar");
	ska.takeDamage(10);
	ska.beRepaired(15);
	ska.challengeNewcomer("Bar");
	return (0);
}
