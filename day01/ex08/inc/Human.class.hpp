/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:48:37 by irhett            #+#    #+#             */
/*   Updated: 2018/01/11 00:08:14 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CLASS_HPP
# define HUMAN_CLASS_HPP

# include <iostream>
# include <string>
# include <map>


class Human {

public:

	Human(void);
	Human(std::string name);
	Human(Human const & old);
	~Human(void); // to be updated

	Human			&operator=(Human const &old);

	std::string		getName(void) const;
	void			action(std::string const & action_name, std::string const & target);

private:

	std::string		_name;
	std::map		<std::string, void(Human::*)(std::string const &)> _abilities; 

	void			meleeAttack(std::string const & target);
	void			rangedAttack(std::string const & target);
	void			intimidatingShout(std::string const & target);

};

std::ostream	&operator<<(std::ostream &o, Human const &c);

#endif
