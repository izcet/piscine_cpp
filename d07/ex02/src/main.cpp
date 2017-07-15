/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/13 14:36:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Array.class.hpp"
#include "Array.class.cpp"

int		main(void)
{
	int			a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	Array<int>	arr(8);
	unsigned int	i = 0;

	while (i < 8)
	{
		arr[i] = a[i];
		i++;
	}

	std::cout << arr << std::endl;

	Array<int>	arrb(arr);

	std::cout << arrb << std::endl;

	arr[2] = 69;
	arrb[4] = 420;

	std::cout << arr << std::endl;
	std::cout << arrb << std::endl;

	arrb = arr;

	arrb[3] = 0;

	std::cout << arr << std::endl;
	std::cout << arrb << std::endl;


	return (0);
}
