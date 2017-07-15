/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include "Enemy.class.hpp"
#include <iostream>
#include <string>
#include "Environment.hpp"
#include "Game.hpp"
#include "Player.class.hpp"
// DEFAULT CONSTUCTOR
Enemy::Enemy(void) {
  Environment yes;
  this->_initValue();
  this->_posX = yes.starShift() % (Game::maxX - 1);
  this->_posY = (yes.starShift() % Game::maxY / 2) + 2;
  return;
}

// CONSTRUCTOR WITH START POSITION
Enemy::Enemy(int x, int y) {
  this->_initValue();
  this->_posX = x;
  this->_posY = y;
  return;
}

// CONSTRUCTOR COPYING EXISTING ENEMY
Enemy::Enemy(Enemy const &old) {
  //	std::srand(std::time(NULL));
  *this = old;
  return;
}

// DEFAULT DECONSTRUCTOR
Enemy::~Enemy(void) { return; }

Enemy &Enemy::operator=(Enemy const &old) {
  this->_name = old._name;
  this->_posX = old._posX;
  this->_posY = old._posY;
  this->_dirX = old._dirX;
  this->_dirY = old._dirY;
  this->_speed = old._speed;
  this->_symbol = old._symbol;
  this->_lives = old._lives;
  return (*this);
}

/*=============================================================================

                                    METHODS

=============================================================================*/

// void Enemy::shoot(std::string gun)
// {
// 	std::cout << "Shooting with " << gun << std::endl;
// 	//Missile::_instantiate(this->_posX + 1, this->_posY + 1);
// }

bool Enemy::move(void) {
  if (this->_posX + this->_dirX + 5 == Game::maxX ||
      this->_posX + this->_dirX - 1 == 0) {
    this->_dirX *= -1;
    this->_dirY = 1;
  } else
    this->_dirY = 0;
  this->_posX += this->_dirX;
  this->_posY += this->_dirY;
  return (true);
}

void Enemy::doAction(WINDOW *enemyWin) {
  if (!this->_isAlive) return;
  bool hit = false;
  hit = this->move();
  init_pair(5, COLOR_RED, COLOR_BLACK);
  if (!this->_isAlive) return;
  wattron(enemyWin, COLOR_PAIR(6));
  mvwprintw(enemyWin,this->_posY, this->_posX, "   _   ");
  wattron(enemyWin, COLOR_PAIR(5));
  mvwprintw(enemyWin,this->_posY + 1, this->_posX, "__/_\\__ ");
  wattroff(enemyWin, COLOR_PAIR(5));
  wattroff(enemyWin, COLOR_PAIR(6));

}

void Enemy::resurrect(void)
{
  this->_posX = rand() % (Game::maxX - 1);
  this->_posY = rand() % (Game::maxY / 2) + 2;
  this->_isAlive = true;
}

void Enemy::getHit(void) {
  this->_lives--;
  this->_isAlive = false;
  this->_posY = 1;
  this->_posX = 1;
  std::cout << '';
}

// INIT

void Enemy::_initValue(void) {
  this->_name = "Enemy";
  this->_posX = 0;
  this->_posY = 0;
  this->_dirX = 1;
  this->_dirY = 0;
  this->_speed = 1;
  this->_symbol = 'X';
  this->_lives = 5;
  this->_isAlive = true;
}

int Enemy::getPosX(void) const { return (this->_posX); }

int Enemy::getPosY(void) const { return (this->_posY); }

int Enemy::getAmount(void) const { return (this->_amount); }

bool Enemy::getIsAlive(void) const { return (this->_isAlive); }

int Enemy::_amount = 10;
