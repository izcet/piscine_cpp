/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:48:59 by irhett            #+#    #+#             */
/*   Updated: 2017/07/05 16:27:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact {

public:

	Contact();
	~Contact();

	void			set_content(void);
	void			get_search(int i) const;
	void			get_content(void) const;

private:

	std::string		_first_name;
	std::string		_last_name;
	std::string		_nick_name;
	std::string		_login;
	std::string		_postal_address;
	std::string		_email_address;
	std::string		_phone_number;
	std::string		_birth_date;
	std::string		_favorite_meal;
	std::string		_underwear_color;
	std::string		_darkest_secret;
};

#endif
