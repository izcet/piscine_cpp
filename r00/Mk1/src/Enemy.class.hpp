/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/
#ifndef ENEMY_CLASS_HPP
#define ENEMY_CLASS_HPP

#include <iostream>
#include <string>
#include "GameEntity.class.hpp"

class Enemy : public AGameEntity {
 public:
  // Constructors & Deconstructors
  Enemy(void);
  Enemy(int x, int y);
  Enemy(Enemy const &old);
  ~Enemy(void);  // to be updated

  // Canonical Constructor
  Enemy &operator=(Enemy const &old);

  // Methods
  bool move(void);
  void getHit(void);
  void _initValue(void);
  void doAction(WINDOW *enemyWin);
  void resurrect(void);
  int getPosX(void) const;
  int getPosY(void) const;
  int getAmount(void) const;
  bool getIsAlive(void) const;

 private:
  static int _amount;  // amount of enemies
  std::string name;    // name of enemy
};

#endif
