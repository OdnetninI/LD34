#include "Events/EventManager.hpp"

void EventManager::setWindow(sf::RenderWindow* window) {
    this->m_window = window;
}

bool EventManager::getKey(sf::Keyboard::Key key) {
    if (sf::Keyboard::isKeyPressed(key)) return true;
    return false;
}

void EventManager::update() {
    while (this->m_window->pollEvent(this->m_event)) {
        if (this->m_event.type == sf::Event::Closed)
            this->m_window->close();

        if (this->m_event.type == sf::Event::GainedFocus)
            this->m_focused = true;

        if (this->m_event.type == sf::Event::LostFocus)
            this->m_focused = false;
    }
}

bool EventManager::isFocused() {
    return this->m_focused;
}
