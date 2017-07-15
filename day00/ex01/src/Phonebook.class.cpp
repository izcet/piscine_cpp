/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:04:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/05 16:26:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void) : num_entries(0) {
	return;
}

Phonebook::~Phonebook(void) {
	return;
}

void		Phonebook::add(void)
{
	if (this->num_entries < 8)
	{
		this->_entries[this->num_entries].set_content();
		this->num_entries++;
	}
	else
		std::cout << "ERROR!?";
}

void		Phonebook::search(void) const
{
	int				i;
	std::string		selection;

	i = 0;
	if (this->num_entries > 0)
	{
		while (i < this->num_entries)
		{
			this->_entries[i].get_search(i);
			i++;
		}
		std::cout << "Pick an entry between 0 and " << this->num_entries - 1;
		std::cout << " (inclusive)" << std::endl;
		std::cout << "All other inputs will be discarded: ";
		std::getline(std::cin, selection);
		i = selection[0] - '0';
		if (i >= 0 && i < this->num_entries)
			this->_entries[i].get_content();
		else
			std::cout << "Invalid response '" << selection << "'" << std::endl;
	}
	else
		std::cout << "There are no entries." << std::endl;
}
