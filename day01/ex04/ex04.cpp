/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:29:04 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 15:32:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main(void)
{
	std::string		brain;
	std::string		*pointer;
	std::string		&reference = brain;

	brain = "HI THIS IS BRAIN";
	pointer = &brain;

	std::cout << "String:\t\t" << brain << std::endl;
	std::cout << "Pointer:\t" << *pointer << std::endl;
	std::cout << "Reference:\t" << reference << std::endl;

	return (0);
}
