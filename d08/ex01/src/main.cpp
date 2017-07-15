/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/14 18:30:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <ctime>

int		randomNum(void)
{
	return (rand() % 200);
}

int 	main(void)
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	///// advanced tests /////
	
	std::vector<int> vec (10000);
	std::generate(vec.begin(), vec.end(), randomNum);

	Span naps = Span(10000);
	naps.addRange(vec);
	std::cout << naps.shortestSpan() << std::endl;
	std::cout << naps.longestSpan() << std::endl;

	return (0);
}
