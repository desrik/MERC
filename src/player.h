#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

class Player : public Creature
{
public:
  Player( std::string name, char sym, nc_color color ) :
    Creature( name, sym, color ) {}
  Player( std::string name, int y, int x, char sym, nc_color color ) :
    Creature( name, y, x, sym, color ) {}

  void handle_input( int ch )
  {
    switch( ch )
    {
    case KEY_RIGHT:
      move( 0, 1 );
      break;
    case KEY_PPAGE:
      move( -1, 1 );
      break;
    case KEY_UP:
      move( -1, 0 );
      break;
    case KEY_HOME:
      move( -1, -1 );
      break;
    case KEY_LEFT:
      move( 0, -1 );
      break;
    case KEY_END:
      move( 1, -1 );
      break;
    case KEY_DOWN:
      move( 1, 0 );
      break;
    case KEY_NPAGE:
      move( 1, 1 );
      break;
    default:
      break;
    }
  }
};

#endif
