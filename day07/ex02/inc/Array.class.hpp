/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:07:44 by irhett            #+#    #+#             */
/*   Updated: 2017/07/13 14:25:24 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <iostream>
# include <string>

template<typename T>
class Array {

public:

	class IndexOutOfBoundsException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Array index is out of bounds");
			}
	};

	Array(void);
	Array(unsigned int n);
	Array(Array<T> const & old);
	~Array(void);

	Array			&operator=(Array const &old);

	T				operator[](unsigned int i) const;
	T				&operator[](unsigned int i);
	
	unsigned int	size(void) const;
	
private:

	T				*_array;
	unsigned int	_len;

};

template<typename T>
std::ostream	&operator<<(std::ostream &o, Array<T> const &c);

#endif
