#include "Game.hpp"
#include <iostream>
#include "State/State.hpp"
#include "State/Undyne.hpp"

int Game::run () {
  this->m_window.create(sf::VideoMode(WIN_X, WIN_Y), WIN_T);
  this->m_eventmng.setWindow(&this->m_window);
  this->m_window.setFramerateLimit(60);
  this->m_statemng.push(new Undyne(&this->m_window,
                                      &this->m_eventmng,
                                      &this->m_statemng,
                                      &this->m_textMaker));

  while (this->m_window.isOpen()) {
    this->m_eventmng.update();

    // Reset frame clock
    this->m_frameTime = this->m_frameClock.restart();

    State* actualState = this->m_statemng.getLast();
    if (actualState != nullptr) actualState->update(this->m_frameTime);

    this->m_window.clear(sf::Color::Black);

    if (actualState != nullptr) actualState->render(this->m_frameTime);

    this->m_window.display();

    this->m_statemng.update();
  }

  return 0;
}
