/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 13:21:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.class.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{

	public:
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & old);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &old);


		void				execute(Bureaucrat const &executor) const;
		std::string			getTarget(void) const;

		std::string			getColor(void) const;

	private:

		const std::string	_target;
		const std::string	_color;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &c);

#endif
