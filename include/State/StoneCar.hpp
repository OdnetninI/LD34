#ifndef __STONE_CAR_HPP__
#define __STONE_CAR_HPP__

#include "State/State.hpp"
#include "Utils/Sprite.hpp"
#include <vector>

class StoneCar : public State {
  public:
    StoneCar (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker);

    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~StoneCar();

  private:
    Sprite car;
    Sprite road;
    int scrollx;
    sf::Texture _rock;

    std::vector<sf::Sprite> rocas;

    sf::Time keyDelay;
    sf::Time rockDelay;
    float rockSpeed = 2;
    float rockRate = 3;
    uint32_t puntos = 0;

    sf::Text* score;
};

#endif // __STONE_CAR_HPP__
