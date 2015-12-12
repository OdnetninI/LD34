#ifndef __FLOWER_HPP__
#define __FLOWER_HPP__

#include "Utils/Sprite.hpp"

class Flower {
  private:
    int lluvia;
    int sol;
    int etapa;
    int error;
    Sprite sprite;

  public:
    Flower(std::string texturas, int w, int h, int TW, int TH, int rain, int sol, int error);
    void grow();
    void kill();
    Sprite* getSprite();
    int getLluvia();
    int getSol();
    int getError();
    int getEtapa();
    ~Flower();
};

#endif // __FLOWER_HPP__
