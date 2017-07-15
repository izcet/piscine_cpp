/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 21:44:29 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Human.class.hpp"

Human::Human(void) {
	return;
}

Human::~Human(void) {
	return;
}

std::string		Human::identify(void) const
{
	return (this->_b.identify());
}

const Brain	&Human::getBrain(void) const
{
	return (this->_b);
}
