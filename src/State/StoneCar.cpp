#include "State/StoneCar.hpp"

StoneCar::StoneCar (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker) {
    this->m_window = window;
    this->m_eventmng = events;
    this->m_statemng = states;
    this->m_textMaker = textmaker;

}

StoneCar::~StoneCar () {

}

void StoneCar::update(sf::Time deltatime) {

}

void StoneCar::render(sf::Time deltatime) {

}
