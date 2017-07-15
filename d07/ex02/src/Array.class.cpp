/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:07:44 by irhett            #+#    #+#             */
/*   Updated: 2017/07/13 14:34:39 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.class.hpp"

template<typename T>
Array<T>::Array(void) : _len(0) {
	this->_array = new T[0];
	return;
}

template<typename T>
Array<T>::Array(unsigned int size) : _len(size) {
	this->_array = new T[this->_len];
	return;
}

template<typename T>
Array<T>::Array(Array<T> const &old) {
	this->_len = old.size();
	this->_array = new T[this->_len];
	unsigned int i = 0;
	while (i < this->_len)
	{
		this->_array[i] = old[i];
		i++;
	}
	return;
}

template<typename T>
Array<T>::~Array(void) {
	delete this->_array;
	return;
}

template<typename T>
Array<T>			&Array<T>::operator=(Array const &old)
{
	delete this->_array;
	this->_len = old.size();
	this->_array = new T[this->_len];
	unsigned int i = 0;
	while (i < this->_len)
	{
		this->_array[i] = old[i];
		i++;
	}
	return (*this);
}

template<typename T>
T					Array<T>::operator[](unsigned int i) const
{
	if (i > this->_len)
		throw IndexOutOfBoundsException();
	return (this->_array[i]);
}

template<typename T>
T					&Array<T>::operator[](unsigned int i)
{
	if (i > this->_len)
		throw IndexOutOfBoundsException();
	return (this->_array[i]);
}

template<typename T>
unsigned int		Array<T>::size(void) const
{
	return (this->_len);
}

template<typename T>
std::ostream	&operator<<(std::ostream &o, Array<T> const &c)
{
	o << "Array(" << c.size() << "){";
	unsigned int i = 0;
	while (i < c.size())
	{
		o << c[i];
		if (i != c.size() - 1)
			o << ", ";
		i++;
	}
	o << "}";
	return (o);
}
