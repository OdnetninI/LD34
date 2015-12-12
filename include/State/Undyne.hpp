#ifndef __UNDYNE_HPP__
#define __UNDYNE_HPP__

#include "State/State.hpp"
#include "Game/UndyneSpears.hpp"
#include "Utils/Sprite.hpp"
#include <vector>

class Undyne : public State {
  public:
    Undyne (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker);

    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~Undyne();

  private:
    std::vector<UndyneSpear> spears;
    Sprite greenEmeraldofHeart;
    int myDir;

    sf::Time delaySpear;
    sf::Time keyBoardDelay;

    sf::Text* score;
    uint32_t puntos;
};

#endif // __UNDYNE_HPP__
