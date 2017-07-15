/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 16:48:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Intern.class.hpp"
#include "Form.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor" << std::endl;
	return;
}

Intern::Intern(Intern const &old) {
	std::cout << "Intern Copy Constructor" << std::endl;
	*this = old;
	return;
}

Intern::~Intern(void) {
	std::cout << "Intern Destructor" << std::endl;
	return;
}

Intern			&Intern::operator=(Intern const &old)
{
	std::cout << "Intern Assignment Operator" << std::endl;
	(void)old;
	return *this;
}

Form			*Intern::makeForm(std::string type, std::string target)
{
	Form	*f;

	if (type.compare("robotomy request") == 0)
		f = new RobotomyRequestForm(target);
	else if (type.compare("presidential pardon") == 0)
		f = new PresidentialPardonForm(target);
	else if (type.compare("shrubbery creation") == 0)
		f = new ShrubberyCreationForm(target);
	else
		throw FormNotKnownException();
	std::cout << *this << " made a " << *f << std::endl;
	return f;
}

std::ostream		&operator<<(std::ostream &o, Intern const &c)
{
	o << "Internary Inter Int Turn Intern";
	(void)c;
	return (o);
}
