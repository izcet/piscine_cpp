/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
#include "GameEntity.class.hpp"

class Player : public AGameEntity {
 public:
  // methods
  void shoot(std::string gun);
  bool move(int key);
  bool checkCollisionObject(char c);
  bool checkCollision(int x, int y);
  void draw(void) const;

  // operator overloads
  Player &operator=(Player const &rhs);  // Canonical

  Player(int startX, int startY);  // Canonical
  Player(Player const &src);       // canonical
  Player(void);                    // Canonical
  ~Player(void);                   // Canonical
  int getPosX(void) const;
  int getPosY(void) const;
  void takeDamage(void);
  void drawPlayer(WINDOW *enemyWin) const;
  bool getIsAlive(void) const;
  int getLives(void) const;
  void setScore(int score);
  int getScore(void) const;

 private:
  void _initValue(void);
  int _score;
};

#endif
