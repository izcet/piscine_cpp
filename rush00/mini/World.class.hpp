/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:03:40 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 22:19:19 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_CLASS_HPP
# define WORLD_CLASS_HPP

# include <iostream>
# include <string>

class List;
class Player;
class Entity;
class Bullet;

class World {

	public:

		World(int height, int width);
		~World(void);

		void			addEnemy(void);
		void			addEnemy(int x);
		void			addBullet(Bullet &b);

		bool			doCycle(void);

		int				getWidth(void) const;
		int				getHeight(void) const;

		Entity			***grid;
		int				key;
		bool			_cleanup(void);
		int				score;

	private:
		World(void);
		World(World const & old);
		World			&operator=(World const &old);

		void			_act(List *Entities);
		List			*_clean(List *Entities);
		void			_deleteList(List *ent);
		List			*_addList(List *li, Entity *ent);


		int				_width;
		int				_height;

		List			*_Bullets;
		List			*_Enemies;
		Player			*_Player;

};

std::ostream	&operator<<(std::ostream &o, World const &c);

#endif
