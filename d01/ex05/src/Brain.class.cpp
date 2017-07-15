/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 21:33:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#include "Brain.class.hpp"

Brain::Brain(void) : _num_ideas(42) {
	return;
}

Brain::~Brain(void) {
	this->_num_ideas = this->_num_ideas + 1;
	return;
}

std::string		Brain::identify(void) const
{
	std::stringstream	ss;

	ss << this;
	return (ss.str());
}
