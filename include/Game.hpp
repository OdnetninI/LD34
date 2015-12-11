#ifndef __GAME_HPP__
#define __GAME_HPP__

#define WIN_X 832
#define WIN_Y 512
#define WIN_T "LD 34"

#include <SFML/Graphics.hpp>
#include "State/StateManager.hpp"
#include "Events/EventManager.hpp"
#include "Utils/TextMaker.hpp"

class Game {
  private:
   sf::RenderWindow m_window;
   StateManager m_statemng;
   EventManager m_eventmng;
   TextMaker m_textMaker;
   sf::Clock               m_frameClock;
   sf::Time                m_frameTime;

  public:
    int run ();
};

#endif // __GAME_HPP__
