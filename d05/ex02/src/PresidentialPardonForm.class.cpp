/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 13:34:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "PresidentialPardonForm.class.hpp"
#include "Form.class.hpp"
#include "Bureaucrat.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	Form(25, 5, "Presidential Pardon"),
	_target(target),
	_color("blue")
{
	std::cout << "PresidentialPardonForm Parametric Constructor" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &old) {
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = old;
	return;
}

PresidentialPardonForm			&PresidentialPardonForm::operator=(PresidentialPardonForm const &old)
{
	std::cout << "PresidentialPardonForm assignment operator" << std::endl;
	if (this != &old)
		return *(new PresidentialPardonForm(old));
	return *this;
}


std::string			PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void				PresidentialPardonForm::execute(Bureaucrat const &exe) const
{
	this->Form::execute(exe);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox,";
	std::cout << " President of the Galaxy" << std::endl;
}

std::string			PresidentialPardonForm::getColor(void) const
{
	return this->_color;
}

std::ostream		&operator<<(std::ostream &o, PresidentialPardonForm const &c)
{
	o << "(" << c.getTarget() << " " << c.Form::getName() << ", sign ";
	o << c.Form::getSignGrade() << ", exec " << c.Form::getExecGrade();
	o << ", Signed?=" << c.Form::getSigned() << ")";
	return (o);
}
