#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include <SFML/Graphics.hpp>

class EventManager {
  public:
    sf::RenderWindow* m_window;
    sf::Event m_event;
    bool m_focused = true;;

    void setWindow (sf::RenderWindow* window);
    void update();
    bool getKey(sf::Keyboard::Key key);
    bool isFocused ();
};

#endif // __EVENT_MANAGER_HPP__
