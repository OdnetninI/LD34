#ifndef __GAME_SELECTION_HPP__
#define __GAME_SELECTION_HPP__

#include "State/State.hpp"
#include "Utils/Sprite.hpp"

class GameSelection : public State {
  public:
    GameSelection (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker);

    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~GameSelection();

  private:
    Sprite BG;
    Sprite Flower;
    Sprite undyne;
    Sprite stoneCar;
    Sprite Selector;
    int opcion;

    sf::Time delayKeys;
};

#endif // __GAME_SELECTION_HPP__
