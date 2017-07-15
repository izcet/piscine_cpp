/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:47:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/11 13:21:37 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.class.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{

	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & old);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &old);

		void				execute(Bureaucrat const &executor) const;
		std::string			getTarget(void) const;

	private:

		const std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &c);

#endif
