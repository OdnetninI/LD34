#ifndef __STONE_CAR_HPP__
#define __STONE_CAR_HPP__

#include "State/State.hpp"

class StoneCar : public State {
  public:
    StoneCar (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker);

    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~StoneCar();

  private:

};

#endif // __STONE_CAR_HPP__
