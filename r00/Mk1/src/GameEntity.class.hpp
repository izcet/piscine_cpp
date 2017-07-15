/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#ifndef GAMEENTITY_CLASS_HPP
#define GAMEENTITY_CLASS_HPP
#include <ncurses.h>
#include <iostream>
#include <string>

class AGameEntity {
 public:
  bool move(int x, int y);
  virtual bool getAlive(void) const;
  virtual void drawToWindow(void) const;
  virtual ~AGameEntity(void) = 0;

 protected:
  std::string _name;
  int _posX;
  int _posY;
  int _dirX;
  int _dirY;
  int _speed;
  char _symbol;
  int _lives;
  bool _isAlive;
  char pos;
};

#endif

// printf("%s", str);
// scanf(""%s", str);

// wprintw(x, y, "%s%s%s", str, strw);
// wscanw(x, y "%c" c);
