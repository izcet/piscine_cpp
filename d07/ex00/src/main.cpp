/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:51:00 by irhett            #+#    #+#             */
/*   Updated: 2017/07/12 15:53:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

	template<typename T>
void	swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

	template<typename T>
T		&min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

	template<typename T>
T		&max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

	template<typename T>
void	print(T &a, T &b)
{
	std::cout << "a: '" << a << "'" << std::endl;
	std::cout << "b: '" << b << "'" << std::endl;
	std::cout << "Minimum of the two: '" << min(a, b) << "'" << std::endl;
	std::cout << "Maximum of the two: '" << max(a, b) << "'" << std::endl;
	std::cout << std::endl;
}

void	theirmain(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int		main(void)
{
	int		a = 5;
	int		b = 10;

	print(a, b);
	swap(a, b);
	print(a, b);

	double	aa = 5.5;
	double	bb = 10.4;

	print(aa, bb);
	swap(aa, bb);
	print(aa, bb);

	std::string	aaa = "aaah!";
	std::string bbb = "will this work?";

	print(aaa, bbb);
	swap(aaa, bbb);
	print(aaa, bbb);

	theirmain();
	return (0);
}
