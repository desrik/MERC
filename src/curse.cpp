#include "curse.h"

BANE::BANE() {

}

BANE::~BANE() {
  endwin();
}

bool BANE::init()
{
  initscr();
  //scrollok( stdscr, TRUE );
  keypad( stdscr, TRUE );
  cbreak();
  noecho();
  curs_set( 0 );
  clear();

  return true;
}

void BANE::color( bool setting )
{

}

PANEL *BANE::new_window( int width, int height, int x, int y )
{
  WINDOW *w;
  w = newwin( height, width, y, x );
  PANEL* p = new_panel(w);
  return p;
}

PANEL *BANE::new_subwindow( WINDOW *parent, int width, int height, int x, int y)
{
  WINDOW *w;
  w = derwin( parent, height, width, y, x );
  PANEL* p = new_panel(w);
  box( w, 0, 0 );

  return p;
}

void BANE::delete_window( WINDOW *w )
{
  char s = ' ';
  wborder( w, s, s, s, s, s, s, s, s );
  wrefresh( w );
  delwin( w );
}
