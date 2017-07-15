/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:47:38 by rschramm          #+#    #+#             */
/*   Updated: 2017/07/08 11:47:40 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"
#include <menu.h>
#include <ncurses.h>
#include <unistd.h>
#include "Game.hpp"
#include "Screen.hpp"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

Menu::Menu(int one) : Screen(one) {
  i = 0;
  c = 0;
  _menu = 0;

  instantiate_settings();
  while ((c = wgetch(_my_win)) != KEY_F(1)) {
    if (!input_loop(c)) break;
    overlay(_my_win, stdscr);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(_my_menu);
  free_menu(_my_menu);
  for (i = 0; i < _n_choices; ++i) free_item(_my_items[i]);
}

Menu::~Menu(void) {
  wclear(_my_win);
  wprintw(_my_win, "Good bye :[\n");
  overlay(_my_win, stdscr);
  sleep(1);
}

void Menu::menu_change(int zero) {
  if (zero == 1)
    _menu++;
  else
    _menu--;
  if (_menu < 0)
    _menu = 1;
  else if (_menu > 1)
    _menu = 0;
}

int Menu::input_loop(int c) {
  Game test;

  switch (c) {
    case KEY_DOWN:
      menu_driver(_my_menu, REQ_DOWN_ITEM);
      menu_change(1);
      break;
    case KEY_UP:
      menu_driver(_my_menu, REQ_UP_ITEM);
      menu_change(0);
      break;
    case '\n':
      if (_menu == 0) {
        wclear(_my_win);
        test.launch();
        wclear(_my_win);
        return (1);
      } else if (_menu == 1)
        return (0);
  }
  return (1);
}

void Menu::instantiate_settings(void) {
  char *choices[] = {(char *)"Play :", (char *)"Exit :", (char *)NULL};
  char *desc[] = {(char *)"...if you dare...", (char *)"sad :[", (char *)NULL};
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  _n_choices = ARRAY_SIZE(choices);
  ITEM **_my_items = new ITEM *[sizeof(ITEM *)];
  for (i = 0; i < _n_choices; i++) _my_items[i] = new_item(choices[i], desc[i]);
  _my_menu = new_menu((ITEM **)_my_items);
  _my_win = newwin(10, 40, 4, 4);
  keypad(_my_win, TRUE);
  set_menu_win(_my_menu, _my_win);
  set_menu_sub(_my_menu, derwin(_my_win, 6, 38, 3, 1));
  set_menu_mark(_my_menu, " * ");
  box(_my_win, 0, 0);
  print_in_middle(_my_win, 1, 0, 40, (char *)"Meet Your Generator: A Game",
                  COLOR_PAIR(1));
  mvwaddch(_my_win, 2, 0, ACS_LTEE);
  mvwhline(_my_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(_my_win, 2, 39, ACS_RTEE);
  print_xxx();
  mvprintw(LINES - 2, 2, "Press Return to Exit");
  // refresh();
  post_menu(_my_menu);
  overlay(_my_win, stdscr);
}

void Menu::print_xxx(void) { mvprintw(LINES + 1, 2, "HI SUP DOG"); }

void Menu::print_in_middle(WINDOW *win, int starty, int startx, int width,
                           std::string string, chtype color) {
  int length, x, y;
  float temp;

  if (win == NULL) win = stdscr;
  getyx(win, y, x);
  if (startx != 0) x = startx;
  if (starty != 0) y = starty;
  if (width == 0) width = 80;

  length = string.length();
  temp = (width - length) / 2;
  x = startx + (int)temp;
  wattron(win, color);
  mvwprintw(win, y, x, "%s", string.c_str());
  wattroff(win, color);
  // refresh();
}

void Menu::PrintOptions(void) { wprintw(_my_win, "In development... \n"); }
