/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:48:44 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 13:41:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP

#include <string>

class Pony {

	public:

		Pony(std::string nam, std::string col, bool spark);
		~Pony(void);

	private:
		std::string	_name;
		std::string	_color;
		bool		_sparkly;

};

#endif
