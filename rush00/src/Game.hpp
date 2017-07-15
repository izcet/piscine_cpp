#include <ncurses.h>
#ifndef GAME_HPP
#define GAME_HPP
#include "Menu.hpp"

class Game {
 public:
  //! Default constructor
  Game();

  //! Copy constructor
  Game(const Game &other);

  //! Destructor
  virtual ~Game();

  //! Copy assignment operator
  Game &operator=(const Game &other);

  void launch();
  void play();

  static WINDOW *enemyWin;
  static WINDOW *playerWin;
  static int score;
  static int maxY;
  static int maxX;
  static bool debug;
  // GameEntity	*getEntityAt(int x, int y);
  void bulletsAct(void);
  void playerAct(void);
  void enemiesAct(void);
  void spawnEnemies(void);
  void cleanup(void);

 protected:
 private:
  // GameEntity		**_grid;
  // Enemy			*_enemies;
  // Bullet			*_bullets;
  // Environment	*_e;
  // Player			*_p;
};

#endif
