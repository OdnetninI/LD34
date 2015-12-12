#ifndef __SPLASH_SCREEN_HPP__
#define __SPLASH_SCREEN_HPP__

#include "State/State.hpp"
#include "Utils/Sprite.hpp"

class SplashScreen : public State {
  public:
    SplashScreen (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker);

    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~SplashScreen();

  private:
    Sprite BG;
    sf::Time counter;
    int alpha;
};

#endif // __SPLASH_SCREEN_HPP__
