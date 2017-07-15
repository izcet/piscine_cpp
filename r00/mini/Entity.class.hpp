/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 20:27:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <iostream>
# include <string>

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

class World;

class Entity {

	public:
		Entity(char type, int x, int y, int dir, char symbol, bool alive);
		virtual ~Entity(void);

		virtual void	act(World &w);

		virtual	int		getSymbol(void) const;
		bool			isAlive(void) const;
		int				getX(void) const;
		int				getY(void) const;

		void			die(void);
		void			collision(Entity &a, Entity &b);

		char			type;

	private:
		Entity			&operator=(Entity const &old);

		Entity(const Entity *ent);
		Entity(Entity const & old);

	protected:
		
		void			moveUp(World &w);
		void			moveDown(World &w);
		void			moveLeft(World &w);
		void			moveRight(World &w);

		Entity			*getLeft(World &w) const;
		Entity			*getRight(World &w) const;
		Entity			*getUp(World &w) const;
		Entity			*getDown(World &w) const;

		bool			_alive;
		int				_x;
		int				_y;
		int				_direction;
		int				_symbol;
};

std::ostream		&operator<<(std::ostream &o, Entity const &c);

#endif
