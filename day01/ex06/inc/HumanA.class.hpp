/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:48:44 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 23:12:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <string>
#include "Weapon.class.hpp"

class HumanA {

	public:

		HumanA(std::string name, Weapon &wep);
		~HumanA(void);

		void	attack(void) const;

	private:
		
		std::string		_name;
		Weapon			&_wep;
};

#endif
