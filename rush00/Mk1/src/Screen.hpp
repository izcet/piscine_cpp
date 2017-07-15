/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:59:06 by rschramm          #+#    #+#             */
/*   Updated: 2017/07/06 16:59:07 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
#define SCREEN_H
#include <ncurses.h>
#include <iostream>

class Screen {
 public:
  Screen(void);
  Screen(int one);
  ~Screen(void);
  void create_newwin(int height, int width, int starty, int startx);
  WINDOW *get_window(void);
  void destroy_win(void);
  // Menu & operator=(Menu const & rhs);

 public:
  int _width;
  int _height;
  int _startx;
  int _starty;
  WINDOW *_my_win;
};

#endif
