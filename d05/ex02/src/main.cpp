/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 13:42:23 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

#include <string>
#include <iostream>
#include <unistd.h>

#define	NEWLINE	std::cout << std::endl

int		main(void)
{
	Form *h = new ShrubberyCreationForm("House");
	Form *r1 = new RobotomyRequestForm("Prostitution");
	Form *r2 = new RobotomyRequestForm("Pizza Delivery");
	Form *r3 = new RobotomyRequestForm("Vlad Yudushkin");
	Form *r4 = new RobotomyRequestForm("Love");
	Form *r5 = new RobotomyRequestForm("Software Engineering");
	Form *p = new PresidentialPardonForm("Edward Snowden");

	NEWLINE;

	Bureaucrat	alice(145, "Alice");
	Bureaucrat	bob(70, "Bob");
	Bureaucrat	carol(15, "Carol");
	Bureaucrat	dave(4, "Dave");

	srand(time(0));

	NEWLINE;
	NEWLINE;
	NEWLINE;

	bob.executeForm(*h);
	NEWLINE;
	alice.signForm(*h);
	NEWLINE;
	alice.executeForm(*h);
	NEWLINE;
	bob.executeForm(*h);

	NEWLINE;
	NEWLINE;
	NEWLINE;

	bob.executeForm(*r1);
	NEWLINE;
	bob.signForm(*r1);
	NEWLINE;
	bob.signForm(*r2);
	NEWLINE;
	bob.signForm(*r3);
	NEWLINE;
	bob.signForm(*r4);
	NEWLINE;
	bob.signForm(*r5);
	NEWLINE;
	carol.executeForm(*r1);
	NEWLINE;
	carol.executeForm(*r2);
	NEWLINE;
	carol.executeForm(*r3);
	NEWLINE;
	carol.executeForm(*r4);
	NEWLINE;
	carol.executeForm(*r5);

	NEWLINE;
	NEWLINE;
	NEWLINE;

	carol.signForm(*p);
	NEWLINE;
	dave.executeForm(*p);

	NEWLINE;
	NEWLINE;
	NEWLINE;
	
	delete h;
	delete r1;
	delete r2;
	delete r3;
	delete r4;
	delete r5;
	delete p;
	return (0);
}
