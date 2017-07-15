/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:34:33 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 23:09:50 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>

class Weapon {

	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string	getType(void) const;
		void				setType(std::string newType);

	private:
		std::string		_type;

};

#endif
