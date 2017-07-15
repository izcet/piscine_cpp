/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:59:48 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 20:30:58 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Entity.class.hpp"
#include "Bullet.class.hpp"
#include "World.class.hpp"

Bullet::Bullet(int direction, int x, int y) : 
	Entity('b', x, y, direction, '|', true)
{
	//std::cout << "Bullet Parametric Constructor" << std::endl;
	return;
}

Bullet::~Bullet(void) {
//	std::cout << "Bullet Destructor" << std::endl;
	return;
}

void				Bullet::act(World &w)
{
	Entity	*e;

	if (this->_alive)
	{
		switch (this->_direction) {
			case NORTH:
				e = this->Entity::getUp(w);
				if (e)
					collision(*this, *e);
				else
					this->Entity::moveUp(w);
				break;
			case SOUTH:
				e = this->Entity::getDown(w);
				if (e)
					collision(*this, *e);
				else
					this->Entity::moveDown(w);
				break;
			case EAST:
				e = this->Entity::getRight(w);
				if (e)
					collision(*this, *e);
				else
					this->Entity::moveRight(w);
				break;
			case WEST:
				e = this->Entity::getLeft(w);
				if (e)
					collision(*this, *e);
				else
					this->Entity::moveLeft(w);
				break;
			default:
				std::cout << "Bullet " << this->_symbol << " is confused!";
				break;
		}
	}
}

int				Bullet::getSymbol(void) const
{
	if (!this->_alive)
		return (' ');
	if (this->_direction == NORTH || this->_direction == SOUTH)
		return ('|');
	return ('-');
}

std::ostream	&operator<<(std::ostream &o, Bullet const &c)
{
	o << "To String Function of Bullet";
	(void)c;
	return (o);
}
