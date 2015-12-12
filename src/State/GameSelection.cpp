#include "State/GameSelection.hpp"
#include "State/FlowerPlant.hpp"
#include "State/StoneCar.hpp"
#include "State/Undyne.hpp"

GameSelection::GameSelection (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker) {
  this->m_window = window;
  this->m_eventmng = events;
  this->m_statemng = states;
  this->m_textMaker = textmaker;

  BG.load("Data/SelectorBG.png");

  Flower.load("Data/Flower Plant.png");
  Flower.getSprite()->setPosition(25,25);

  undyne.load("Data/Undyne.png");
  undyne.getSprite()->setPosition(25+128+25,25);

  stoneCar.load("Data/StoneCar.png");
  stoneCar.getSprite()->setPosition(25+128+25+128+25,25);

  Selector.load("Data/Selector.png");
  Selector.getSprite()->setPosition(25,25);

  opcion = 0;
}

GameSelection::~GameSelection () {

}

void GameSelection::update(sf::Time deltatime) {
  if (!m_eventmng->isFocused()) return;

  delayKeys += deltatime;
  if (delayKeys >= sf::seconds(0.3)) {
    if (m_eventmng->getKey(sf::Keyboard::Return)) {
      if (opcion == 0) m_statemng->pushLooped(new FlowerPlant(m_window, m_eventmng, m_statemng, m_textMaker));
      if (opcion == 1) m_statemng->pushLooped(new Undyne(m_window, m_eventmng, m_statemng, m_textMaker));
      if (opcion == 2) m_statemng->pushLooped(new StoneCar(m_window, m_eventmng, m_statemng, m_textMaker));

      delayKeys = sf::Time::Zero;
    }
    else if (m_eventmng->getKey(sf::Keyboard::Right)) {opcion++; delayKeys = sf::Time::Zero;}
    else if (m_eventmng->getKey(sf::Keyboard::Left)) {opcion--; delayKeys = sf::Time::Zero;}
    else
      delayKeys -= deltatime;
  }

  if (opcion < 0) opcion = 2;
  if (opcion > 2) opcion = 0;

  if (opcion == 0) Selector.getSprite()->setPosition(25,25);
  if (opcion == 1) Selector.getSprite()->setPosition(25+128+25,25);
  if (opcion == 2) Selector.getSprite()->setPosition(25+128+25+128+25,25);

}

void GameSelection::render(sf::Time deltatime) {
  BG.render(m_window);
  Flower.render(m_window);
  undyne.render(m_window);
  stoneCar.render(m_window);
  Selector.render(m_window);
}
