#include "Screen.hpp"
#include <unistd.h>

// Non fullscreen mode

Screen::Screen(void)
    : _width(15),
      _height(3),
      _startx((COLS - _width) / 2),
      _starty((LINES - _height) / 2) {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  printw("Welcome to early riser\n");
  printw("Press f1 to exit\n");
  refresh();
  sleep(1);
  create_newwin(_height, _width, _starty, _startx);
}

// For fullscreen mode

Screen::Screen(int one)
    : _width(0),
      _height(0),
      _startx((COLS - _width) / 2),
      _starty((LINES - _height) / 2) {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  printw("Welcome to early riser\n");
  printw("Press f1 to exit\n");
  refresh();
  sleep(1);
  one = 0;
  create_newwin(one, one, one, one);
}

void Screen::create_newwin(int height, int width, int starty, int startx) {
  _my_win = newwin(height, width, starty, startx);
  box(_my_win, 0, 0); /* 0, 0 gives default characters
                       * for the vertical and horizontal
                       * lines			*/
  wrefresh(_my_win);  /* Show that box 		*/
}

WINDOW *Screen::get_window(void) { return (_my_win); }

void Screen::destroy_win(void) {
  /* box(local_win, ' ', ' '); : This won't produce the desired
   * result of erasing the window. It will leave it's four corners
   * and so an ugly remnant of window.
   */
  wborder(_my_win, 'a', '*', '*', '*', '*', '*', '*', '*');
  /* The parameters taken are
   * 1. win: the window on which to operate
   * 2. ls: character to be used for the left side of the window
   * 3. rs: character to be used for the right side of the window
   * 4. ts: character to be used for the top side of the window
   * 5. bs: character to be used for the bottom side of the window
   * 6. tl: character to be used for the top left corner of the window
   * 7. tr: character to be used for the top right corner of the window
   * 8. bl: character to be used for the bottom left corner of the window
   * 9. br: character to be used for the bottom right corner of the window
   */
  wrefresh(_my_win);
  delwin(_my_win);
}

Screen::~Screen(void) {
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  printw("Goodbye\n");
  endwin();
}
/*Menu::Menu & operator=(Menu const & rhs)
{

}*/
