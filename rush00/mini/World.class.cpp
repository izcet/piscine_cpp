/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:03:40 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 22:19:42 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "World.class.hpp"
#include "Entity.class.hpp"
#include "Enemy.class.hpp"
#include "Bullet.class.hpp"
#include "List.class.hpp"
#include "Player.class.hpp"

World::World(int height, int width) :
	score(0),
	_width(width),
	_height(height)
{
	int		x;
	int		y;

	this->grid = new Entity**[this->_height];
	y = 0;
	while (y < height)
	{
		this->grid[y] = new Entity*[this->_width];
		x = 0;
		while (x < height)
			this->grid[y][x++] = nullptr;
		y++;
	}
	this->_Player = new Player(height / 2, width / 2);
	this->grid[this->_Player->getY()][this->_Player->getX()] = this->_Player;
	this->_Bullets = new List();
	this->_Enemies = new List();
	std::cout << "New World Created" << std::endl;
	this->key = -1;
	return;
}

World::~World(void) {
	this->_deleteList(this->_Bullets);
	this->_deleteList(this->_Enemies);
	delete this->_Player;
	delete this->grid;
	return;
}

void			World::addEnemy(void)
{
	this->addEnemy(this->_width);
}

void			World::addEnemy(int x)
{
	Entity 	*e;

	if (this->grid[0][x])
		return;
	e = (Entity*)(new Enemy(x));
	this->grid[e->Entity::getY()][e->Entity::getX()] = e;
	this->_Enemies = this->_addList(this->_Enemies, e);
}

void			World::addBullet(Bullet &b)
{
	this->grid[b.getY()][b.getX()] = &b;
	this->_Bullets = this->_addList(this->_Bullets, (Entity*)&b);
}

int				World::getWidth(void) const
{
	return (this->_width);
}

int				World::getHeight(void) const
{
	return (this->_height);
}

bool			World::doCycle(void) // maybe this is going to take inputs
{
	this->_act(this->_Bullets);
	this->_Player->act(*this);
	this->_act(this->_Enemies);
	return (true);
}

void			World::_act(List *ent)
{
	if (!ent->isEmpty())
	{
		this->_act(ent->next);
		ent->getEnt()->act(*this);
	}
}

bool			World::_cleanup(void)
{
	this->_Bullets = this->_clean(this->_Bullets);
	this->_Enemies = this->_clean(this->_Enemies);
	return (this->_Player->isAlive());
}	

List			*World::_clean(List *ent)
{
	List	*next;

	if (ent->isEmpty())
		return (ent);
	if (ent->getEnt()->isAlive())
	{
		ent->next = this->_clean(ent->next);
		return (ent);
	}
	next = ent->next;
	this->grid[ent->getEnt()->getY()][ent->getEnt()->getX()] = nullptr;
	delete ent->getEnt();
	delete ent;
	return (next);
}

void			World::_deleteList(List *ent)
{
	if (!ent->isEmpty())
	{
		this->_deleteList(ent->next);
		delete (ent->getEnt());
	}
	delete (ent);
}

List			*World::_addList(List *li, Entity *ent)
{
	List	*node;

	node = new List(ent);
	node->next = li;
	return (node);
}

std::ostream	&operator<<(std::ostream &o, World const &c)
{
	o << "To String Function of World: ";
	(void)c;
	return (o);
}

World::World(World const &old) {
	std::cout << "SUCK A DICK GRANDPA" << std::endl;
	*this = old;
	return;
}

World			&World::operator=(World const &old)
{
	std::cout << "DON'T EVEN THINK ABOUT IT" << std::endl;
	(void)old;
	return *this;
}

World::World(void) : _width(0), _height(0) {
	std::cout << "DO NOT CALL ME" << std::endl;
	return;
}
