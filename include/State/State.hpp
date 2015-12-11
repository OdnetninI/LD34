#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <SFML/Graphics.hpp>
#include "State/StateManager.hpp"
#include "Events/EventManager.hpp"
#include "Utils/TextMaker.hpp"

class State {
  public:
    sf::RenderWindow* m_window;
    EventManager* m_eventmng;
    StateManager* m_statemng;
    TextMaker* m_textMaker;

    State(sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker) {
        this->m_window = window;
        this->m_eventmng = events;
        this->m_statemng = states;
        this->m_textMaker = textmaker;
    }

    virtual void update (sf::Time deltatime) = 0;
    virtual void render (sf::Time deltatime) = 0;

    virtual ~State() {}
};

#endif // __STATE_HPP__
