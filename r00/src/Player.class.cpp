/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include "Player.class.hpp"
#include <ncurses.h>
#include <iostream>
#include <string>
#include "Game.hpp"

// METHODS //

void Player::shoot(std::string gun) {
  std::cout << "Shooting with " << gun << std::endl;
  // Missile::_instantiate(this->_posX + 1, this->_posY + 1);
}

bool Player::move(int key) {
  if (this->_isAlive == false) return (false);
  if (key == KEY_UP && this->_posY - 1 > 0) this->_posY = this->_posY - 1;
  if (key == KEY_DOWN && this->_posY + 1 < Game::maxY)
    this->_posY = this->_posY + 1;
  if (key == KEY_LEFT && this->_posX - 1 > 0) this->_posX = this->_posX - 1;
  if (key == KEY_RIGHT && this->_posX + 1 < Game::maxX)
    this->_posX = this->_posX + 1;
  return (true);
}

void Player::setScore(int score)
{
  this->_score += score;
}

int Player::getScore(void) const
{
  return this->_score;
}

// OPERATOR OVERLOADS //

Player &Player::operator=(Player const &rhs) {
  this->_posX = rhs._posX;
  this->_posY = rhs._posY;
  this->_dirX = rhs._dirX;
  this->_dirY = rhs._dirY;
  this->_speed = rhs._speed;
  this->_symbol = rhs._symbol;
  this->_isAlive = rhs._isAlive;
  this->_name = rhs._name;
  return *this;
}

// CONSTRUCTORS //

Player::Player(int startX, int startY) {
  this->_initValue();
  this->_posX = startX;
  this->_posY = startY;
  if (Game::debug) {
    std::cout << "Player " << this->_name << " has been created!" << std::endl;
  }
}

Player::Player(Player const &src) {
  *this = src;
  if (Game::debug) {
    std::cout << "Player " << this->_name << " has been created!" << std::endl;
  }
  return;
}

Player::Player(void) {
  this->_initValue();
  // std::cout << "Player has been created!" << std::endl;
  // mvwprintw(Game::playerWin, Game::maxX / 2, Game::maxY / 2, "Player has been
  // created!");
}

// DECONSTRUCTORS //

Player::~Player(void) {
  mvwprintw(stdscr, Game::maxX / 2, Game::maxY / 2,
            "Player has been destroyed!");
  return;
}

// INIT //

void Player::_initValue(void) 
{
  this->_name = "PlayerOne";
  this->_posX = 0;
  this->_posY = 0;
  this->_dirX = 1;
  this->_dirY = 1;
  this->_speed = 1;
  this->_symbol = '^';
  this->_lives = 5;
  this->_isAlive = true;
  this->_score = 0;
}

int Player::getPosX(void) const { return (this->_posX); }

int Player::getPosY(void) const { return (this->_posY); }

void Player::takeDamage(void) 
{
  this->_lives--;
  if (this->_lives <= 0) {
    this->_isAlive = false;
    this->_symbol = 'V';
  }
}

void Player::drawPlayer(WINDOW *playerWin) const
{
  start_color();
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  wattron(playerWin, COLOR_PAIR(4));
  mvwprintw(playerWin,this->_posY, this->_posX, "  ^  ");
  mvwprintw(playerWin,this->_posY + 1, this->_posX, " / \\ ");
  mvwprintw(playerWin,this->_posY + 2, this->_posX, "/ %c \\", '8');
  mvwprintw(playerWin,this->_posY + 3, this->_posX, "\\ ^ /");
  mvwprintw(playerWin,this->_posY + 4, this->_posX, " V V ");
  wattroff(playerWin, COLOR_PAIR(4));
}

bool Player::getIsAlive(void) const { return (this->_isAlive); }

int Player::getLives(void) const { return (this->_lives); }
