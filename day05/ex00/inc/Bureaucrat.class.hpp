/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/10 14:24:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
# include <string>
class Bureaucrat {

public:

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Grade is TOO HIGH!");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Grade is TOO LOW!");
			}
	};

	Bureaucrat(void);
	Bureaucrat(int grade, const std::string name);
	Bureaucrat(Bureaucrat const & old);
	~Bureaucrat(void);
	Bureaucrat			&operator=(Bureaucrat const &old);

	const std::string	getName(void) const;
	int					getGrade(void) const;

	void				incrementGrade(void);
	void				decrementGrade(void);

private:
	const std::string	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &c);

#endif
