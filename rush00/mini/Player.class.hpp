/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:51:30 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 21:57:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include <iostream>
# include <string>
# include "Entity.class.hpp"

class World;
class Bullet;

class Player : public Entity {

	public:

		Player(int x, int y);
		~Player(void);

		virtual void	act(World &w);
		virtual int		getSymbol(void) const;

		char			type;

	private:

		void			_move(World &w);
		void			_shoot(World &w);

		int				_moveStep;
		int				_moveMax;

};

std::ostream	&operator<<(std::ostream &o, Player const &c);

#endif
