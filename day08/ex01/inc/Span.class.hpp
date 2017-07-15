/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:11:34 by irhett            #+#    #+#             */
/*   Updated: 2017/07/14 18:30:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

class Span
{
	public:
		class NotEnoughSpaceException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Span is already full.");
				}
		};

		class NoSuchRangeException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Not enough items to span.");
				}
		};

		Span(void);
		Span(unsigned int const);
		Span(Span const & ref);
		~Span(void);
		Span & operator=(Span const & ref);

		void	addNumber(int const);
		int		shortestSpan(void);
		int		longestSpan(void);
		template <typename T>
		void	addRange(T t)
		{
			for_each(t.begin(), t.end(), 
					std::bind1st(std::mem_fun(&Span::addNumber), this));
		}

		unsigned int		getLen(void) const;
		std::vector<int>	getCont(void) const;

	private:
		unsigned int		_len;
		std::vector<int>	_cont;
};

# endif
