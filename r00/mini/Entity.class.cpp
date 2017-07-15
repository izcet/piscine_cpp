/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 21:13:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Entity.class.hpp"
#include "World.class.hpp"


Entity::Entity(char type, int x, int y, int dir, char sym, bool alive) :
	type(type),
	_alive(alive),
	_x(x),
	_y(y),
	_direction(dir),
	_symbol(sym)
{
	return;
}

void			Entity::act(World &w)
{
	(void)w;
}

int				Entity::getSymbol(void) const
{
	return (this->_symbol);
}

bool			Entity::isAlive(void) const
{
	return (this->_alive);
}

int				Entity::getX(void) const
{
	return (this->_x);
}

int				Entity::getY(void) const
{
	return (this->_y);
}

void			Entity::die(void)
{
	this->_alive = false;
}

void			Entity::collision(Entity &a, Entity &b)
{
	a.die();
	b.die();
}

// MOVEMENT HELPERS /////////////////////////////

void			Entity::moveUp(World &w)
{
	if (this->_y > 0)
	{
		this->_y = this->_y - 1;
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y + 1][this->_x] = nullptr;
	}
	else
		this->die();
}

void			Entity::moveDown(World &w)
{
	if (this->_y < w.getHeight() - 1)
	{
		this->_y = this->_y + 1;
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y - 1][this->_x] = nullptr;
	}
	else
		this->die();
}

void			Entity::moveLeft(World &w)
{
	if (this->_x > 0)
	{
		this->_x = this->_x - 1;
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y][this->_x + 1] = nullptr;
	}
	else
		this->die();

}

void			Entity::moveRight(World &w)
{
	if (this->_x < w.getWidth() - 1)
	{
		this->_x = this->_x + 1;
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y][this->_x - 1] = nullptr;
	}
	else
		this->die();

}

// LOCATION COLLISION HELPERS //////////////////////

Entity			*Entity::getLeft(World &w) const
{
	if (this->_x > 0)
		return (w.grid[this->_y][this->_x - 1]);
	return (nullptr);
}

Entity			*Entity::getRight(World &w) const
{
	if (this->_x < w.getWidth() - 1)
		return (w.grid[this->_y][this->_x + 1]);
	return (nullptr);
}

Entity			*Entity::getUp(World &w) const
{
	if (this->_y > 0)
		return (w.grid[this->_y - 1][this->_x]);
	return (nullptr);
}

Entity			*Entity::getDown(World &w) const
{
	if (this->_y < w.getHeight() - 1)
		return (w.grid[this->_y + 1][this->_x]);
	return (nullptr);
}

// BELOW HERE BE SOME CRAYZ SHIT I DON'T WANT TO DEAL WITH

std::ostream	&operator<<(std::ostream &o, Entity const &c)
{
	o << "ENTITY TOSTREAM";
	(void)c;
	return (o);
}

Entity::~Entity(void) {
//	std::cout << "Entity Destructor" << std::endl;
	return;
}
