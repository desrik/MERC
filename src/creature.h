#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <map>
#include "color.h"
#include "enums.h"

class Creature
{
  int _x, _y;
  char _symbol;
  nc_color _color;

  std::string _name;

public:
  Creature( std::string name, char sym, nc_color color )
  {
    _name = name;
    _y = 0;
    _x = 0;
    _symbol = sym;
    _color = color;
  }
  Creature( std::string name, int y, int x, char sym, nc_color color )
  {
    _name = name;
    _y = y;
    _x = x;
    _symbol = sym;
    _color = color;
  }

  void pos( int y, int x )
  {
    _y = y;
    _x = x;
  }
  void move( int y, int x )
  {
    _y += y;
    _x += x;
  }

  int y()
  {
    return _y;
  }
  int x()
  {
    return _x;
  }
  char symbol()
  {
    return _symbol;
  }
  nc_color color()
  {
    return _color;
  }
};

#endif

