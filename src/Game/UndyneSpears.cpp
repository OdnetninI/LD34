#include "Game/UndyneSpears.hpp"

// Important line in static variables
sf::Texture UndyneSpear::_spear;

void UndyneSpear::loadTexture(std::string filename) {
  _spear.loadFromFile(filename);
}

UndyneSpear::UndyneSpear() {
  spear.setTexture(_spear);
}

sf::Sprite* UndyneSpear::getSprite() {
  return &this->spear;
}

int UndyneSpear::getDir() {
  return this->dir;
}

void UndyneSpear::setDir(int dir) {
    this->dir = dir;
}
