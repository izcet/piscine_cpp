/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 16:41:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

class Form;

class Intern {

public:

	class FormNotKnownException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("I don't know what this is.");
			}
	};

	Intern(void);
	Intern(Intern const & old);
	~Intern(void);
	Intern			&operator=(Intern const &old);

	Form				*makeForm(std::string name, std::string target);

private:
};

std::ostream	&operator<<(std::ostream &o, Intern const &c);

#endif
