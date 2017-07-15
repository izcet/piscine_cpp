/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include "Missile.class.hpp"
#include "Game.hpp"
#include "Player.class.hpp"

// CONSTRUCTORS //

Missile::Missile(void) {
  this->_initValue();
  return;
}

Missile::Missile(int x, int y) {
  this->_initValue();
  this->_posX = x;
  this->_posY = y;
  return;
}

Missile::Missile(Missile const &old) {
  std::srand(std::time(NULL));
  *this = old;
  return;
}

Missile::~Missile(void) { return; }

// GETTERS //

int Missile::getPosX(void) { return (this->_posX); }

int Missile::getPosY(void) { return (this->_posY); }

// OPERATOR OVERLOAD //

Missile &Missile::operator=(Missile const &old) {
  if (this == &old)
    return (*this);
  else {
    this->_posX = old._posX;
    this->_posY = old._posY;
    this->_symbol = old._symbol;
  }
  return (*this);
}

bool Missile::move(void) {
  if (this->_posY - 1 == 0) {
    this->_isAlive = false;
    return (false);
  } else
    this->_posY -= 1;
  return (true);
}

bool Missile::takeAction(WINDOW *wind) {
  if (!this->_isAlive) return (false);
  bool hit = false;
  hit = this->move();
  this->drawMissile(wind);
  return (hit);
}

void Missile::drawMissile(WINDOW *wind) const {
  init_pair(6, COLOR_GREEN, COLOR_BLACK);
  wattron(wind, COLOR_PAIR(6));
  if (this->_isAlive) mvwaddch(wind, this->_posY, this->_posX, this->_symbol);
  wattroff(wind, COLOR_PAIR(6));
}

// INIT //

void Missile::_initValue(void) {
  this->_name = "Missile";
  this->_posX = Game::maxX / 2;
  this->_posY = Game::maxY;
  this->_speed = 1;
  this->_symbol = ':';
  this->_lives = 1;
  this->_isAlive = false;
}

void Missile::getHit(void) {
  this->_lives -= 1;
  this->_isAlive = false;
}

void Missile::setIsAlive(bool shot) { this->_isAlive = shot; }

void Missile::setPos(int x, int y) {
  this->_posX = x;
  this->_posY = y - 1;
}

bool Missile::getIsAlive(void) const { return (this->_isAlive); }
