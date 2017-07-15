/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/10 14:32:40 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(void) :
	_name("Dolores Umbridge"),
	_grade(50)
{
	std::cout << "Bureaucrat Default Constructor" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(int grade, const std::string name) :
	_name(name)
{
	std::cout << "Bureaucrat Parametric Constructor" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &old) {
	std::cout << "Bureaucrat Copy Constructor" << std::endl;
	*this = old;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat Destructor" << std::endl;
	return;
}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &old)
{
	std::cout << "Bureaucrat Assignment Operator" << std::endl;
	if (this != &old)
		this->_grade = old.getGrade();
	return *this;
}

const std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int					Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void				Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void				Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream		&operator<<(std::ostream &o, Bureaucrat const &c)
{
	o << c.getName() << ", bureaucrat grade " << c.getGrade();
	return (o);
}
