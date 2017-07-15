/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:30:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 22:33:40 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "World.class.hpp"
#include "List.class.hpp"
#include "Player.class.hpp"
#include "Entity.class.hpp"
#include "Enemy.class.hpp"
#include "Bullet.class.hpp"
#include <ncurses.h>
#include <unistd.h>
int main(void)
{
	int		x;
	int		y;
	int		sym;

	initscr();
	timeout(20);
	getmaxyx(stdscr, y, x);
	keypad(stdscr, TRUE);
	World	w(y, x);

	bool	going;
	int		count;

	going = true;
	srand(time(NULL));
	count = 0;
	while (going)
	{
		// window.drawStars;
		w.key = getch();
		w.doCycle();
		clear();
		count+= rand() % 20;
		if (count >= 200)
		{
			w.addEnemy();
			count = 0;
		}
		y = 0;
		while (y < w.getHeight())
		{
			x = 0;
			while (x < w.getWidth())
			{
				if (w.grid[y][x])
				{
					sym = w.grid[y][x]->getSymbol();
					mvaddch(y, x, sym);
					;
				}
				else
				{

				}
				x++;
			}
			y++;
		}
		refresh();
		going = w._cleanup();
	}
	sleep(5);
	endwin();
	std::cout << "\t\tGAME OVER" << std::endl;
	std::cout << "Your final score was: " << w.score << std::endl;
	return (0);
}
