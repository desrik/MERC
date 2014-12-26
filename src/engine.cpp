#include "engine.h"
#include "curse.h"
#include "world.h"

#define LOG_WIDTH getmaxx(stdscr)/3

Engine::Engine()
{
  m_running = true;
  need_update = true;
}

Engine::~Engine() {

}

int Engine::run()
{
  init();

  while(m_running) {
    int ch = getch();
    handle_input(ch);
    update();
    draw();
    if(need_update) {
      doupdate();
    }
  }
}

bool Engine::init()
{
  bane.init();

  world.init(100,100);

  getmaxyx(stdscr, m_height, m_width);

  screen = bane.new_window(100, 100 - 2, 0, 0);
  wborder( screen->win, '|', '|', '-', '-', '+', '+', '+', '+' );
  viewport = bane.new_subwindow(screen->win, m_width, m_height, 0, 0);
  messages = bane.new_window(LOG_WIDTH, m_height-2, m_width - LOG_WIDTH, 0);
  wborder( messages->win, '|', '|', '-', '-', '+', '+', '+', '+' );
  status = bane.new_window(m_width, 3, 0, m_height - 3);
  box(status->win, 0, 0);
  //wborder( status->win, '|', '|', '-', '-', '+', '+', '+', '+' );
  draw();
  update_panels();
  doupdate();
}

void Engine::handle_input( int ch )
{
  switch( ch )
  {
  case 'm':
    if(panel_hidden(messages)) {
      show_panel(messages);
      hide_panel(status);
      show_panel(status);
      update_panels();
    } else {
      hide_panel(messages);
      update_panels();
    }
    break;
  case 'q':
  case 'Q':
    m_running = false;
    break;
  default:
    break;
  }
}

void Engine::update()
{

}

void Engine::draw()
{

  for( int dx = 1; dx < m_width - 1; ++dx ) {
    for( int dy = 1; dy < m_height; ++dy ) {
        if(dx == 5 && dy == 5) {
          mvwaddch( screen->win, dy, dx, '#');//world->terrain_at( dx, dy ) );
        } else {
          mvwaddch( screen->win, dy, dx, world.terrain_at(dx, dy));//world->terrain_at( dx, dy ) );
        }
    }
  }
  //update_panels();
}
