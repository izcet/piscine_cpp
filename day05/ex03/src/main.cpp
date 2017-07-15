/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 16:45:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

#include "Intern.class.hpp"

#include <string>
#include <iostream>
#include <unistd.h>

#define	NEWLINE	std::cout << std::endl

int		main(void)
{
	Bureaucrat	boss(1, "The Big Boss");
	Bureaucrat	lesserBoss(10, "The Smaller Boss");
	Intern	scrub;
	Form *f;

	NEWLINE;
	NEWLINE;
	NEWLINE;

	f = scrub.makeForm("robotomy request", "Intern");
	lesserBoss.signForm(*f);
	lesserBoss.executeForm(*f);
	delete f;

	NEWLINE;
	NEWLINE;

	f = scrub.makeForm("presidential pardon", "Zaphod Beeblebrox");
	lesserBoss.signForm(*f);
	boss.executeForm(*f);
	delete f;

	NEWLINE;
	NEWLINE;

	f = scrub.makeForm("shrubbery creation", "Epic");
	boss.signForm(*f);
	lesserBoss.executeForm(*f);
	delete f;

	NEWLINE;
	NEWLINE;
	NEWLINE;
	return (0);
}
