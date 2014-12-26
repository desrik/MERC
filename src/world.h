#ifndef WORLD_H
#define WORLD_H


class World
{
  int p;
  int px, py;

  int m_width, m_height;

  std::vector< std::vector< int > > terrain;
  public:
    World();
    ~World();
    bool init(int w, int h);

    int terrain_at(int x, int y);
    int width();
    int height();
  private:
    bool load_terrain();
    void generate();
};

#endif // WORLD_H
