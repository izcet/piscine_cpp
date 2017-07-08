/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:25:13 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:40:11 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {

public:

	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & old);
	~ClapTrap(void);
	
	ClapTrap &		operator=(ClapTrap const &old);

	int				rangedAttack(std::string const &target);
	int				meleeAttack(std::string const &target);
	int				takeDamage(unsigned int amount);
	int				beRepaired(unsigned int amount);

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

	ClapTrap(void);

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

std::ostream &	operator<<( std::ostream & o, ClapTrap const & c);


#endif
