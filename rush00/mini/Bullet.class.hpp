/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:59:48 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 21:56:57 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <iostream>
# include <string>

class Entity;
class World;

class Bullet : public Entity{

public:

	Bullet(int direction, int x, int y);
	~Bullet(void);

	virtual void	act(World &w);
	virtual int		getSymbol(void) const;

};

std::ostream	&operator<<(std::ostream &o, Bullet const &c);

#endif
