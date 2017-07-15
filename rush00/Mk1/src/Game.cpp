/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include "Game.hpp"
#include <ncurses.h>
//#include "Enemy.class.hpp"
#include <unistd.h>
#include "Enemy.class.hpp"
#include "Environment.hpp"
#include "GameEntity.class.hpp"
#include "Missile.class.hpp"
#include "Player.class.hpp"

int Game::score = 0;
int Game::maxX = 0;
int Game::maxY = 0;
bool Game::debug = false;
WINDOW *Game::enemyWin = NULL;
WINDOW *Game::playerWin = NULL;

Game::Game() {}

Game::Game(const Game &other) { *this = other; }

Game::~Game() {}

Game &Game::operator=(const Game &rhs) {
  // Check for self-assignment!
  if (this == &rhs) return *this;

  return *this;
}

void Game::launch() {
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, maxY, maxX);
  printw("window size id %d tall and %d wide", maxY, maxX);
  play();
}

void Game::play() {
  Environment map;
  int ch = 0;
  keypad(map.getWin(), TRUE);
  // nodelay(map.getWin(), TRUE);
  timeout(1);
  border(0, 0, 0, 0, 0, 0, 0, 0);
  Player playerOne(maxX / 2, maxY - 10);
  playerWin = newwin(0, 0, 0, 0);
  Enemy enemy1(maxX / 2, maxY / 2);
  Enemy massEnemy[50];
  Missile mag[20000];
  int magSize = 19999;
  enemyWin = newwin(0, 0, 0, 0);
  while ((ch = getch()) != 'q') {
    
    if (!playerOne.getIsAlive())
      {
	wclear(stdscr);
	mvwprintw(stdscr, playerOne.getPosY(), playerOne.getPosX(), "Game over!");
	refresh();
	break;
      }
    map.starsRnd();
    playerOne.move(ch);
    if (ch == 32) {
      if (playerOne.getIsAlive())
	{
	  mag[magSize].setPos(playerOne.getPosX() + 2, playerOne.getPosY() + 4);
	  mag[magSize].setIsAlive(true);
	  magSize--;
	}
      // Missile bullet(playerOne.getPosY(), playerOne.getPosX());
    }
    for (int i = 0; i < 20000; i++) {
      if (mag[i].getIsAlive()) {
	for (int y = - 2; y <= 2; y++) {	  
	  for (int x = 0; x < 50; x++) {
	    if (mag[i].getPosX() == massEnemy[x].getPosX() + y &&
		mag[i].getPosY() == massEnemy[x].getPosY() + 2) {
	      mag[i].setIsAlive(false);
	      massEnemy[x].getHit();
	      playerOne.setScore(1);
	    }
	  }
        }
      }
      mag[i].takeAction(playerWin);
    }

    wclear(enemyWin);

    for (int i = 0; i < 50; i++) {
      if (playerOne.getPosX() == massEnemy[i].getPosX() &&
          playerOne.getPosY() + 2 == massEnemy[i].getPosY()) {
	massEnemy[i].getHit();
	playerOne.takeDamage();
      }
      if (!massEnemy[i].getIsAlive()) {
	massEnemy[i].resurrect();
      }	
      massEnemy[i].doAction(enemyWin);
    }
    overlay(enemyWin, stdscr);
    wclear(playerWin);
    for (int i = 0; i <= 20000; i++) {
      if (mag[i].getIsAlive()) mag[i].takeAction(playerWin);
    }
    mvwprintw(playerWin, 2, 2, " lives: %d", playerOne.getLives());
    mvwprintw(playerWin, 3, 2, " score: %d", playerOne.getScore());
    playerOne.drawPlayer(playerWin);
    overlay(playerWin, stdscr);
    refresh();
    ch = 0;
    usleep(16000);
  }
  // delete  enemy1;
}
/*
GameEntity		*Game::getEntityAt(int x, int y)
{
                return (this->grid[x][y]);
}
*/
