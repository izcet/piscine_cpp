/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:25:13 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:28:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap {

public:

	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & old);
	~ScavTrap(void);
	
	ScavTrap &		operator=(ScavTrap const &old);

	int				rangedAttack(std::string const &target);
	int				meleeAttack(std::string const &target);
	int				takeDamage(unsigned int amount);
	int				beRepaired(unsigned int amount);
	std::string		challengeNewcomer(std::string const &target);

	std::string		getName(void) const;
	int				getHP(void) const;
	int				getHPMax(void) const;
	int				getEP(void) const;
	int				getEPMax(void) const;
	int				getLevel(void) const;
	int				getMelee(void) const;
	int				getRange(void) const;
	int				getArmor(void) const;

private:

	ScavTrap(void);

	std::string		_name;
	int				_hp;
	int				_hp_max;
	int				_ep;
	int				_ep_max;
	int				_level;
	int				_dmg_melee;
	int				_dmg_range;
	int				_dr;

};

std::ostream &	operator<<( std::ostream & o, ScavTrap const & c);


#endif
