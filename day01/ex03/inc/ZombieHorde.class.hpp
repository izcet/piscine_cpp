/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:48:44 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 14:35:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_CLASS_HPP
# define ZOMBIEHORDE_CLASS_HPP

#include <string>
#include "Zombie.class.hpp"

class ZombieHorde {

public:

	ZombieHorde(int n);
	~ZombieHorde(void);

	void	announce(void) const;

private:

	int		_num;
	Zombie	**_zoms;
};

#endif
