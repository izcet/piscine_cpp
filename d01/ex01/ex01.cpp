/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 00:05:15 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 00:06:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	memoryLeak()
{
	std::string*	panthere = new std::string("string panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}
