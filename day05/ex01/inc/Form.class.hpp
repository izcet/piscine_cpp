/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/10 20:38:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form {

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

		Form(void);
		Form(int sign, int exec, const std::string name);
		Form(Form const & old);
		~Form(void);
		Form				&operator=(Form const &old);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		void				beSigned(Bureaucrat &b);

	private:
		const std::string	_name;
		bool				_signed;
		int					_signGrade;
		int					_execGrade;
};

std::ostream	&operator<<(std::ostream &o, Form const &c);

#endif
