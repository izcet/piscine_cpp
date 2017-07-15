/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/13 21:59:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

	template<typename T>
void	print(T &a)
{
	std::cout << a << " ";
}

	template<typename T>
void	iter(T *arr, int arr_len, void (*function)(T const &param))
{
	int		i;

	i = 0;
	while (i < arr_len)
	{
		function(arr[i]);
		i++;
	}
}

int		main(void)
{
	int		a[7] = {2, 3, 4, 69, 42, 420, 0};
	float	b[6] = {3.14, 4.2, 2.0 - 1.0, 3.33, 85.0, -.14};

	iter(a, 7, print);
	std::cout << std::endl;
	iter(b, 6, print);
	std::cout << std::endl;
	return (0);
}
