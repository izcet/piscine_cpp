/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2017/07/05 15:49:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phony_book.h"

int		main(void)
{
	Phonebook	phone;
	std::string	response;

	while (1)
	{
		std::cout << "ADD SEARCH or EXIT: ";
		std::getline(std::cin, response);
		if (response.compare("ADD") == 0)
		{
			if (phone.num_entries < NUM_ENTRIES)
				phone.add();
			else
				std::cout << "STOP HAVING FRIENDS!" << std::endl;
		}
		else if (response.compare("SEARCH") == 0)
			phone.search();
		else if (response.compare("EXIT") == 0)
			return (0);
	}
	return (0);
}
