/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 13:47:21 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Pony.class.hpp"


void	ponyOnTheHeap(std::string name)
{
	Pony	*p = new Pony(name, "blue", true);

	delete p;
}

void	ponyOnTheStack(std::string name)
{
	Pony p = Pony(name, "green", false);
}

int		main(void)
{
	std::cout << std::endl;
	std::cout << "HEAP:" << std::endl;
	ponyOnTheHeap("Foobar");
	std::cout << ":HEAP DONE" << std::endl;
	
	std::cout << std::endl;
	std::cout << "STACK:" << std::endl;
	ponyOnTheStack("Barfoo");
	std::cout << ":STACK DONE" << std::endl;

	return (0);
}
