/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/10 20:47:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

#include <string>
#include <iostream>

int		main(void)
{
	Bureaucrat	alice(10, "Alice");
	Bureaucrat	bob(15, "Bob");
	Bureaucrat	carol(20, "Carol");
	Form		f(18, 19, "Legal Papers");

	std::cout << std::endl;
	try {
		Form g(1, 0, "Nuclear Launch Form");
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: ";
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << f << std::endl;
	alice.signForm(f);
	bob.signForm(f);
	carol.signForm(f);

	std::cout << std::endl;
	return (0);
}
