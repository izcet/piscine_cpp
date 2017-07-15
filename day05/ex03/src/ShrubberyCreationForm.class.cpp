/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 13:44:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Form.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "Bureaucrat.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	Form(145, 137, "Shrubbery Creation"),
	_target(target)
{
	std::cout << "ShrubberyCreationForm Parametric Constructor" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &old) {
	std::cout << "ShrubberyCreationForm Copy Constructor" << std::endl;
	*this = old;
	return;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &old)
{
	std::cout << "ShrubberyCreationForm Assignment Operator" << std::endl;
	if (this != &old)
		return (*new ShrubberyCreationForm(old));
	return *this;
}

std::string			ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void				ShrubberyCreationForm::execute(Bureaucrat const &exec) const
{
	int				i;
	std::ofstream	ofs(this->_target + "_shrubbery");

	this->Form::execute(exec);
	i = rand() % 5;
	if (i == 0)
		ofs << "ASCII trees" << std::endl;
	else
	{
		ofs << "           \\/ |    |/" << std::endl;
		ofs << "        \\/ / \\||/  /_/___/_" << std::endl;
		ofs << "         \\/   |/ \\/" << std::endl;
		ofs << "    _\\__\\_\\   |  /_____/_" << std::endl;
		ofs << "           \\  | /          /" << std::endl;
		ofs << "  __ _-----`  |{,-----------~" << std::endl;
		ofs << "            \\ }{" << std::endl;
		ofs << "             }{{" << std::endl;
		ofs << "             }}{" << std::endl;
		ofs << "             {{}" << std::endl;
		ofs << "       , -=-~{ .-^- _" << std::endl;
		ofs << "  ejm        `}" << std::endl;
		ofs << "              {" << std::endl;	
	}
	ofs.close();
}

std::ostream		&operator<<(std::ostream &o, ShrubberyCreationForm const &c)
{
	o << "(" << c.getTarget() << " " << c.Form::getName() << ", sign ";
	o << c.getSignGrade() << ", exec " << c.getExecGrade() << ", Signed?=";
	o << c.getSigned() << ")";
	return (o);
}
