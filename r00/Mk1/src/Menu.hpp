/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:59:06 by rschramm          #+#    #+#             */
/*   Updated: 2017/07/06 16:59:07 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
#define MENU_H
#include <menu.h>
#include <ncurses.h>
#include <iostream>
#include "Screen.hpp"

class Menu : public Screen {
 public:
  Menu(int one);
  ~Menu(void);
  void PrintOptions(void);
  void instantiate_settings(void);
  int input_loop(int c);
  void menu_change(int zero);
  void print_xxx(void);
  void print_in_middle(WINDOW *win, int starty, int startx, int width,
                       std::string string, chtype color);
  MENU *get_menu(void);
  // Menu & operator=(Menu const & rhs);

 protected:
  ITEM **_my_items;
  MENU *_my_menu;
  int _n_choices;
  int i;
  int c;
  int _menu;
  std::string _player_name;
};

#endif
