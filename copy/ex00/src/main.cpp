/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:05:38 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "FragTrap.class.hpp"

int		main(void)
{
	FragTrap	foo("Frank");

	foo.rangedAttack("Bar");
	foo.takeDamage(10);
	foo.meleeAttack("Bar");
	foo.takeDamage(10);
	foo.beRepaired(15);
	foo.vaultHunterDotExe("Bar");
	return (0);
}
