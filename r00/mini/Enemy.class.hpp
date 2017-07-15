/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:29:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 22:22:39 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include <iostream>
# include <string>

class Entity;
class World;

class Enemy : public Entity{

public:

	Enemy(char symbol);
	Enemy(int wid);
	Enemy(int wid, int pos);
	Enemy(int wid, char symbol);
	Enemy(int wid, int pos, char symbol);
	~Enemy(void);
	Enemy			&operator=(Enemy const &old);


	virtual void	act(World &w);
	virtual int		getSymbol(void) const;

	char			type;

private:
	
	int		_moveStep;
	int		_moveMax;
};

std::ostream	&operator<<(std::ostream &o, Enemy const &c);

#endif
