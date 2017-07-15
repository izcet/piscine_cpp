/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/10 20:50:41 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Form.class.hpp"
#include "Bureaucrat.class.hpp"

Form::Form(void) :
	_name("Default Form"),
	_signed(false),
	_signGrade(150),
	_execGrade(1)
{
	std::cout << "Form Default Constructor" << std::endl;
	return;
}

Form::Form(int sign, int exec, const std::string name) :
	_name(name),
	_signed(false),
	_signGrade(sign),
	_execGrade(exec)
{
	std::cout << "Form Parametric Constructor" << std::endl;
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	return;
}

Form::Form(Form const &old) {
	std::cout << "Form Copy Constructor" << std::endl;
	*this = old;
	return;
}

Form::~Form(void) {
	std::cout << "Form Destructor" << std::endl;
	return;
}

Form			&Form::operator=(Form const &old)
{
	std::cout << "Form Assignment Operator" << std::endl;
	if (this != &old)
	{
		this->_signed = false;
		this->_signGrade = old.getSignGrade();
		this->_execGrade = old.getExecGrade();
	}
	return *this;
}

const std::string	Form::getName(void) const
{
	return this->_name;
}

int					Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int					Form::getExecGrade(void) const
{
	return this->_execGrade;
}

bool				Form::getSigned(void) const
{
	return this->_signed;
}

void				Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream		&operator<<(std::ostream &o, Form const &c)
{
	o << "(" << c.getName() << ", sign " << c.getSignGrade();
	o << ", exec " << c.getExecGrade() << ", Signed?=" << c.getSigned() << ")";
	return (o);
}
