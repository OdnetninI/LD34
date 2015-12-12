#ifndef __UNDYNE_SPEARS_HPP__
#define __UNDYNE_SPEARS_HPP__

// ReWrite of Sprite adapted to this situation, don't use in other context

#include <SFML/Graphics.hpp>

/*
  PRE: Load Texture before create objects.
*/
class UndyneSpear {
  private:
    sf::Sprite spear;
    static sf::Texture _spear;
    int dir;

  public:
    UndyneSpear();
    static void loadTexture(std::string filename);
    sf::Sprite* getSprite();
    int getDir();
    void setDir(int dir);
};

#endif // __UNDYNE_SPEARS_HPP__
