/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/14 17:56:25 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <iterator>

class ItemNotFoundException : public std::exception
{
	public:
		virtual const char * what() const throw()
		{
			return ("Item is not in container");
		}
};

template<typename T>
typename T::iterator		easyfind(T &container, int query)
{
	typename T::iterator	it;

	it = find(container.begin(), container.end(), query);
	if ((it) == (container.end()))
		throw ItemNotFoundException();
	return it;
}
