#ifndef __FLOWER_PLANT_HPP__
#define __FLOWER_PLANT_HPP__

#include "State/State.hpp"
#include "Game/Flower.hpp"

class FlowerPlant : public State {
  public:
    FlowerPlant (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker);

    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~FlowerPlant();

  private:
    Flower* flor;
    Sprite fondo;
    Sprite S;
    Sprite L;
    Sprite SBar;
    Sprite LBar;
    Sprite BG;
    int sol;
    int ll;
    int estado; // Lluviax2, lluvia, nada, sol, solx2
    /*
      Lluviax2 -> ll+4 sol-3
      Lluvia -> ll+2 sol -1
      Nada -> ll-1 sol-1
      Sol -> sol+2 ll-1
      Solx2 -> sol+4 ll-3
    */
    uint32_t puntos;
    sf::Time elapsed;   // Button Delay
    sf::Time elapsed2;  // Weather Delay
    sf::Time elapsed3;  // Death Delay

    sf::Text* score;
};

#endif // __FLOWER_PLANT_HPP__
