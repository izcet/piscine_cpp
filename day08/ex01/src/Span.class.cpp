/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:11:52 by irhett            #+#    #+#             */
/*   Updated: 2017/07/14 18:24:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <cmath>

Span::Span(void) : _len(0)
{
	return ;
}

Span::Span(unsigned int const size) : _len(size)
{
	return ;
}

Span::Span(Span const & ref)
{
	*this = ref;
	return ;
}

Span &		Span::operator=(Span const & ref)
{
	if (this == &ref)
		return (*this);
	this->_cont = ref.getCont();
	this->_len = ref.getLen();
	return (*this);
}

Span::~Span(void)
{
	return ;
}

unsigned int		Span::getLen(void) const
{
	return (this->_len);
}

std::vector<int>	Span::getCont(void) const
{
	return (this->_cont);
}

void				Span::addNumber(int const n)
{
	if (this->_cont.size() < this->_len)
		this->_cont.push_back(n);
	else
		throw NotEnoughSpaceException();
}

int					Span::shortestSpan(void)
{
	int							span = 999999;
	int							size = _cont.size();
	std::vector<int>			copy = _cont;

	if (size < 2)
		throw NoSuchRangeException();

	std::sort(copy.begin(), copy.end());
	for (int i = 1; i < size; i++)
	{
		if (span > copy[i] - copy[i - 1])
			span = copy[i] - copy[i - 1];
	}
	return (span);
}

int					Span::longestSpan(void)
{
	int		size = _cont.size();

	if (size < 2)
		throw NoSuchRangeException();

	std::vector<int>	copy;
	copy = _cont;
	std::sort(copy.begin(), copy.end());
	return (abs(copy[0] - copy[size - 1]));
}
