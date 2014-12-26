#include "world.h"

World::World()
{

}

World::~World() {

}

bool World::init(int w, int h)
{
  m_width = w;
  m_height = h;

  p = '@';
  px = 5;
  py = 5;

  load_terrain();
}

int World::terrain_at(int x, int y) {
  return terrain[x][y];
}

bool World::load_terrain()
{
  for(int x = 0; x < m_width; ++x) {
    std::vector<int> tmp;
    for(int y = 0; y < m_height; ++y) {
      if(x == 5 || y == 5) {
        tmp.push_back('#');
      } else {
        tmp.push_back('.');
      }
    }
    terrain.push_back(tmp);
  }
}

void World::generate()
{

}

int World::width() {
  return m_width;
}

int World::height() {
  return m_height;
}
