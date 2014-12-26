#ifndef ENGINE_H
#define ENGINE_H

#include "curse.h"
#include "world.h"

class Engine
{
  int m_width, m_height;

  bool m_running;

  World world;
  BANE bane;
  PANEL* screen;
  PANEL* viewport;
  PANEL* messages;
  PANEL* status;
  bool need_update;
public:
  Engine();
  ~Engine();

  int run();
private:
  bool init();
  void shutdown();

  void handle_input( int ch );
  void update();
  void draw();
};

#endif // ENGINE_H
