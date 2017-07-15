/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:51:30 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 22:15:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Player.class.hpp"
#include "World.class.hpp"
#include "Entity.class.hpp"
#include "Bullet.class.hpp"
#include <ncurses.h>
#define KEY_SHOOT 32


Player::Player(int x, int y) :
	Entity('p', x, y, NORTH, '^', true),
	_moveStep(0),
	_moveMax(5)
{
	return;
}

void			Player::act(World &w)
{
	if (this->Entity::_alive)
	{
		switch (w.key)
		{
			case KEY_UP:
				this->Entity::_direction = NORTH;
				this->_move(w);
				break;
			case KEY_DOWN:
				this->Entity::_direction = SOUTH;
				this->_move(w);
				break;
			case KEY_LEFT:
				this->Entity::_direction = WEST;
				this->_move(w);
				break;
			case KEY_RIGHT:
				this->Entity::_direction = EAST;
				this->_move(w);
				break;
			case KEY_SHOOT:
				this->_shoot(w);
				break;
			default:
				break;
		}
		if (this->_moveStep < this->_moveMax)
			this->_moveStep++;
	}
}

void			Player::_move(World &w)
{
	Entity	*e;

	if (this->_moveStep >= this->_moveMax)
	{
		switch (this->Entity::_direction) {
			case NORTH:
				if (this->Entity::_y > 0)
				{
					e = this->getUp(w);
					if (e)
						collision(*this, *e);
					else
						this->moveUp(w);
				}
				break;

			case SOUTH:
				if (this->Entity::_y < w.getHeight() - 1)
				{
					e = this->getDown(w);
					if (e)
						collision(*this, *e);
					else
						this->moveDown(w);
				}
				break;

			case EAST:
				if (this->Entity::_x < w.getWidth() - 1)
				{
					e = this->getRight(w);
					if (e)
						collision(*this, *e);
					else
						this->moveRight(w);
				}
				break;

			case WEST:
				if (this->Entity::_x > 0)
				{
					e = this->getLeft(w);
					if (e)
						collision(*this, *e);
					else
						this->moveLeft(w);
				}
				break;
			default:
				break;
		}
		this->_moveStep = 0;
	}
}

void			Player::_shoot(World &w)
{
	Bullet	*b;
	switch(this->Entity::_direction)
	{
		case NORTH:
			b = new Bullet(this->Entity::_direction, this->Entity::_x, this->Entity::_y - 1);
			w.addBullet(*b);
			break;
		case SOUTH:
			b = new Bullet(this->Entity::_direction, this->Entity::_x, this->Entity::_y + 1);
			w.addBullet(*b);
			break;
		case EAST:
			b = new Bullet(this->Entity::_direction, this->Entity::_x + 1, this->Entity::_y);
			w.addBullet(*b);
			break;
		case WEST:
			b = new Bullet(this->Entity::_direction, this->Entity::_x - 1, this->Entity::_y);
			w.addBullet(*b);
			break;
	}
}


int				Player::getSymbol(void) const
{
	if (this->Entity::_alive)
	{
		switch(this->Entity::_direction)
		{
			case NORTH:	return '^';
			case SOUTH: return 'v';
			case EAST: return '>';
			case WEST: return '<';
			default: return '?';
		}
	}
	return ('X');
}


Player::~Player(void) {
	return;
}

std::ostream	&operator<<(std::ostream &o, Player const &c)
{
	o << "To String Function of Player: ";
	(void)c;
	return (o);
}
