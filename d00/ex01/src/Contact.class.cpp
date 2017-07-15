/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 21:23:10 by irhett            #+#    #+#             */
/*   Updated: 2017/07/05 16:25:46 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

void	Contact::set_content(void)
{
	std::cout << "What is the first name?" << std::endl;
	std::getline(std::cin, this->_first_name);
	std::cout << "What is the last name?" << std::endl;
	std::getline(std::cin, this->_last_name);
	std::cout << "What is the nickname?" << std::endl;
	std::getline(std::cin, this->_nick_name);
	std::cout << "What is the login?" << std::endl;
	std::getline(std::cin, this->_login);
	std::cout << "What is the postal address?" << std::endl;
	std::getline(std::cin, this->_postal_address);
	std::cout << "What is the email address?" << std::endl;
	std::getline(std::cin, this->_email_address);
	std::cout << "What is the phone number?" << std::endl;
	std::getline(std::cin, this->_phone_number);
	std::cout << "What is the birth date?" << std::endl;
	std::getline(std::cin, this->_birth_date);
	std::cout << "What is the favorite meal?" << std::endl;
	std::getline(std::cin, this->_favorite_meal);
	std::cout << "What is their underwear color?" << std::endl;
	std::getline(std::cin, this->_underwear_color);
	std::cout<< "What is their darkest secret?" << std::endl;
	std::getline(std::cin, this->_darkest_secret);
}

void	Contact::get_search(int index) const
{
	int		len;
	int		i;

	std::cout << "         " << index << "|";
	len = this->_first_name.length();
	i = 0;
	while (len < 10 && i < (10 - len))
	{
		std::cout << " ";
		i++;
	}
	if (len > 10)
		std::cout << this->_first_name.substr(0, 9) << ".|";
	else
		std::cout << this->_first_name << "|";
	len = this->_last_name.length();
	i = 0;
	while (len < 10 && i < (10 - len))
	{
		std::cout << " ";
		i++;
	}
	if (len > 10)
		std::cout << this->_last_name.substr(0, 9) << ".|";
	else
		std::cout << this->_last_name << "|";
	len = this->_nick_name.length();
	i = 0;
	while (len < 10 && i < (10 - len))
	{
		std::cout << " ";
		i++;
	}
	if (len > 10)
		std::cout << this->_nick_name.substr(0, 9) << ".";
	else
		std::cout << this->_nick_name;
	std::cout << std::endl;
}

void	Contact::get_content(void) const
{
	std::cout << "First name:\t" << this->_first_name << std::endl;
	std::cout << "Last name:\t" << this->_last_name << std::endl;
	std::cout << "Nickname:\t" << this->_nick_name << std::endl;
	std::cout << "Login:\t\t" << this->_login << std::endl;
	std::cout << "Postal:\t\t" << this->_postal_address << std::endl;
	std::cout << "Email:\t\t" << this->_email_address << std::endl;
	std::cout << "Phone:\t\t" << this->_phone_number << std::endl;
	std::cout << "Birthday:\t" << this->_birth_date << std::endl;
	std::cout << "Favorite Food:\t" << this->_favorite_meal << std::endl;
	std::cout << "Underwear:\t" << this->_underwear_color << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkest_secret << std::endl;
}
