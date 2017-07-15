/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:25:13 by irhett            #+#    #+#             */
/*   Updated: 2017/07/13 16:50:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.class.hpp"

class ScavTrap : public ClapTrap{

public:

	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & old);
	~ScavTrap(void);
	
	ScavTrap &		operator=(ScavTrap const &old);

	std::string		challengeNewcomer(std::string const &target);

private:

	ScavTrap(void);
};

#endif
