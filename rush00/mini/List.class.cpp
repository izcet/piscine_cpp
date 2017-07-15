/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 20:40:42 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "List.class.hpp"
#include "Entity.class.hpp"

List::List(void) : 
	_empty(true),
	_ent(nullptr) 
{
//	std::cout << "List Default Constructor" << std::endl;
	return;
}

List::List(Entity *ent) : 
	_empty(false), 
	_ent(ent) 
{
//	std::cout << "List Parametric Constructor" << std::endl;
	return;
}

List::List(List const &old) {
//	std::cout << "List Copy Constructor" << std::endl;
	*this = old;
	return;
}

List::~List(void) {
//	std::cout << "List Destructor" << std::endl;
	return;
}

List			&List::operator=(List const &old)
{
//	std::cout << "List Assignment Operator" << std::endl;
	if (this != &old)
	{
		this->_empty = old.isEmpty();
		this->_ent = old.getEnt();
	}
	return *this;
}

bool			List::isEmpty(void) const
{
	return (this->_empty);
}

Entity			*List::getEnt(void) const
{
	return (this->_ent);
}

std::ostream	&operator<<(std::ostream &o, List const &c)
{
	o << "LIST (" << c.getEnt() << ")";
	return (o);
}
