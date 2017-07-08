/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:25:13 by irhett            #+#    #+#             */
/*   Updated: 2017/07/07 23:44:24 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# include <iostream>
# include <string>

class FragTrap : public ClapTrap {

public:

	FragTrap(std::string name);
	FragTrap(FragTrap const & old);
	~FragTrap(void);
	
	FragTrap &		operator=(FragTrap const &old);

	int				vaultHunterDotExe(std::string const &target);

private:

	FragTrap(void);
};

#endif
