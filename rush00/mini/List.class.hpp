/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 18:46:15 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CLASS_HPP
# define LIST_CLASS_HPP

# include <iostream>
# include <string>

class Entity;

class List {

	public:

		List(void);
		List(Entity *ent);
		List(List const & old);
		~List(void);

		List	&operator=(List const &old);

		bool	isEmpty(void) const;
		Entity	*getEnt(void) const;

		List	*next;

	private:
		bool	_empty;
		Entity	*_ent;

};

std::ostream	&operator<<(std::ostream &o, List const &c);

#endif
