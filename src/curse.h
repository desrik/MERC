#ifndef BANE_H
#define BANE_H

class BANE
{
public:
  BANE();
  ~BANE();

  bool init();

  void color( bool setting );

  // windows
  PANEL *new_window( int width, int height, int x, int y );
  PANEL *new_subwindow( WINDOW *parent, int width, int height, int x, int y );
  void delete_window( WINDOW *w );
private:

};


#endif // BANE_H
