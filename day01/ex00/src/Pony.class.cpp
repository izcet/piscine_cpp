/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 13:44:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Pony.class.hpp"

Pony::Pony(std::string nam, std::string col = "white", bool spark = false) : 
	_name(nam),
	_color(col),
	_sparkly(spark)
{
	std::cout << "A new";
	if (this->_sparkly)
		std::cout << " sparkly";
	std::cout << " " << this->_color << " pony named " << this->_name;
	std::cout << " was created." << std::endl;
	return;
}

Pony::~Pony(void) {
	std::cout << this->_name;
	std::cout << " has been destroyed." << std::endl;
	return;
}
