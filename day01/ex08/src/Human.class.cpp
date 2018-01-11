/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:48:37 by irhett            #+#    #+#             */
/*   Updated: 2018/01/11 00:11:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Human.class.hpp"

Human::Human(void) : _name("nothing") {
	std::cout << "A nameless human was created." << std::endl;
	this->_abilities.insert(std::make_pair("melee", &Human::meleeAttack));
	this->_abilities.insert(std::make_pair("range", &Human::rangedAttack));
	this->_abilities.insert(std::make_pair("shout", &Human::intimidatingShout));
	return;
}

Human::Human(std::string name) : _name(name) {
	std::cout << "A human named " << name << " was made." << std::endl;
	this->_abilities.insert(std::make_pair("melee", &Human::meleeAttack));
	this->_abilities.insert(std::make_pair("range", &Human::rangedAttack));
	this->_abilities.insert(std::make_pair("shout", &Human::intimidatingShout));
	return;
}

Human::Human(Human const &old) {
	std::cout << "Human Copy Constructor" << std::endl;
	*this = old;
	return;
}

Human::~Human(void) {
	std::cout << this->getName() << " died." << std::endl;
	return;
}

Human				&Human::operator=(Human const &old)
{
	std::cout << "Human Assignment Operator" << std::endl;
	if (this != &old)
		this->_name = old.getName();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Human const &c)
{
	o << "[a Human named " << c.getName() << "]";
	return (o);
}

void			Human::meleeAttack(std::string const & target)
{
	std::cout << *this << " just fucking punches " << target << " in the face.";
	std::cout << std::endl;
}

void			Human::rangedAttack(std::string const & target)
{
	std::cout << *this << " grabs whatever is in easy reach and throws it at ";
	std::cout << target << "." << std::endl;
}

void			Human::intimidatingShout(std::string const & target)
{
	std::cout << *this << " spits some venomous fire at " << target;
	std::cout << " and really crushes their ego." << std::endl;
}

void			Human::action(std::string const & act, std::string const & target)
{
		void	(Human::*function)(std::string const &) = this->_abilities[act];
		
		(this->*function)(target);
}

std::string 	Human::getName(void) const
{
	return (this->_name);
}
