#include "Game/Flower.hpp"

Flower::Flower (std::string texturas, int w, int h, int TW, int TH, int rain, int sol, int error) {
  sprite.load(texturas);
  sprite.setDimensions(w,h);
  sprite.setTextureDimensions(TW, TH);
  lluvia = rain;
  this->sol = sol;
  this->error = error;
  etapa = 0;
}

void Flower::grow() {
  etapa++;
  if (etapa > 4) etapa = 4;
  sprite.setIndex(etapa);
}

void Flower::kill() {
  etapa = 0;
  sprite.setIndex(etapa);
}

Sprite* Flower::getSprite() {
  return &sprite;
}

int Flower::getLluvia() {
  return lluvia;
}

int Flower::getSol() {
  return sol;
}

int Flower::getEtapa() {
  return etapa;
}

int Flower::getError() {
  return error;
}

Flower::~Flower() {

}
