/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 13:33:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "RobotomyRequestForm.class.hpp"
#include "Form.class.hpp"
#include "Bureaucrat.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	Form(72, 45, "Robotomy Request"),
	_target(target)
{
	std::cout << "RobotomyRequestForm Parametric Constructor" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &old) {
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = old;
	return;
}

RobotomyRequestForm			&RobotomyRequestForm::operator=(RobotomyRequestForm const &old)
{
	std::cout << "RobotomyRequestForm assignment operator" << std::endl;
	if (this != &old)
		return *(new RobotomyRequestForm(old));
	return *this;
}

std::string			RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void				RobotomyRequestForm::execute(Bureaucrat const &exec) const
{
	int				i;

	this->Form::execute(exec);
	i = rand() % 2;
	std::cout << "** makes some drilling noises **" << std::endl;
	if (i == 0)
		std::cout << this->_target << " has been successfully robotomized."; 
	else
		std::cout << "I am a failure.";
	std::cout << std::endl;
}

std::ostream		&operator<<(std::ostream &o, RobotomyRequestForm const &c)
{
	o << "(" << c.getTarget() << " " << c.Form::getName() << ", sign ";
	o << c.getSignGrade() << ", exec " << c.getExecGrade() << ", Signed?=";
	o << c.getSigned() << ")";
	return (o);
}


