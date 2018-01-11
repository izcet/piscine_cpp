/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2018/01/11 00:11:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Human.class.hpp"

int		main(void)
{
	std::cout << "In the beginning... " << std::endl;
	Human	generic;
	Human	alice("Alice");
	Human	bob("bob");

	generic.action("melee", alice.getName());
	alice.action("shout", bob.getName());
	bob.action("range", generic.getName());
	alice.action("melee", bob.getName());

	std::cout << "The end!" << std::endl;

	return (0);
}
