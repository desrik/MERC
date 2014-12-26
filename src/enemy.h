#ifndef ENEMY_H
#define ENEMY_H


#include "creature.h"

class Enemy : public Creature
{
public:
  Enemy( std::string name, char sym, nc_color color ) :
    Creature( name, sym, color ) {}
  Enemy( std::string name, int y, int x, char sym, nc_color color ) :
    Creature( name, y, x, sym, color ) {}
};

#endif

