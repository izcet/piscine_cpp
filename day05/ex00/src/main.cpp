/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/10 14:33:11 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

#include <string>
#include <iostream>

int		main(void)
{
	try {
		Bureaucrat alice(0, "alice");
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: ";
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bob(150, "bob");
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: ";
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat carol(15, "carol");
		while (carol.getGrade() < 200)
		{
			std::cout << "("  << carol << ") going to ";
			carol.decrementGrade();
			std::cout << "(" << carol << ")" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << "Exception caught: ";
		std::cout << e.what() << std::endl;
	}
	return (0);
}
