/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/14 18:01:42 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <iterator>
#include "easyfind.hpp"

int		main(void)
{
	std::list<int>		l1st;

	l1st.push_back(0);
	l1st.push_back(420);
	l1st.push_back(69);
	l1st.push_back(42);
	l1st.push_back(777);
	l1st.push_back(508);
	l1st.push_back(451);
	l1st.push_back(1984);
	l1st.push_back(1);

	std::list<int>::iterator	it;

	it = easyfind(l1st, 42);
	std::cout << *it << std::endl;

	try {
		it = easyfind(l1st, 43);
		std::cout << *it << std::endl;
	}
	catch (ItemNotFoundException e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
