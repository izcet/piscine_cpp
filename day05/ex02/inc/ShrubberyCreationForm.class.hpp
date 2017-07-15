/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 13:20:50 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.class.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{

	public:
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & old);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &old);

		void				execute(Bureaucrat const &executor) const;
		std::string			getTarget(void) const;

	private:

		std::string			_target;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &c);

#endif
