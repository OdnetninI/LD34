#include "State/Undyne.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <ctime>
#include "Events/EventManager.hpp"
#include <sstream>

float SPEED_SPEAR = 2;
#define SPEARS 2
float SPEAR_RATE = 0.8;

Undyne::Undyne (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker) {
    this->m_window = window;
    this->m_eventmng = events;
    this->m_statemng = states;
    this->m_textMaker = textmaker;
    puntos = 0;
    score = m_textMaker->createText();
    score->setCharacterSize(16);
    score->setColor(sf::Color::White);
    score->setPosition(25,25);
    std::srand(std::time(nullptr));

    greenEmeraldofHeart.load("Data/Green Emerald of Heart.png");
    greenEmeraldofHeart.setDimensions(64,64);
    greenEmeraldofHeart.setTextureDimensions(64,256);
    greenEmeraldofHeart.setPosition(WIN_X/2 - 32, WIN_Y/2 - 32);
    greenEmeraldofHeart.setIndex(0);
    myDir = 0;

    UndyneSpear::loadTexture("Data/Undyne Spear.png");

    for (unsigned int i = 0; i < SPEARS; i++) {
      spears.push_back(UndyneSpear());
      spears[i].setDir(-1);
    }
}

Undyne::~Undyne () {

}

void Undyne::update(sf::Time deltatime) {
  if (!m_eventmng->isFocused()) return;
  if (m_eventmng->getKey(sf::Keyboard::Escape))
    m_statemng->popLooped();

  keyBoardDelay += deltatime;
  if (keyBoardDelay >= sf::seconds(0.15)) {
    if (!m_eventmng->getKey(sf::Keyboard::A) && !m_eventmng->getKey(sf::Keyboard::S)) {
      myDir = 0;
      greenEmeraldofHeart.setIndex(0);
      keyBoardDelay = sf::Time::Zero;
    }
    else if (m_eventmng->getKey(sf::Keyboard::A) && !m_eventmng->getKey(sf::Keyboard::S)) {
      myDir = 1;
      greenEmeraldofHeart.setIndex(1);
      keyBoardDelay = sf::Time::Zero;
    }
    else if (m_eventmng->getKey(sf::Keyboard::S) && !m_eventmng->getKey(sf::Keyboard::A)) {
      myDir = 2;
      greenEmeraldofHeart.setIndex(2);
      keyBoardDelay = sf::Time::Zero;
    }
    else if (m_eventmng->getKey(sf::Keyboard::A) && m_eventmng->getKey(sf::Keyboard::S)) {
      myDir = 3;
      greenEmeraldofHeart.setIndex(3);
      keyBoardDelay = sf::Time::Zero;
    }
    else
      keyBoardDelay -= deltatime;
  }

  for (unsigned int i = 0; i < spears.size(); i++) {
    if (spears[i].getDir() != -1) {
      switch (spears[i].getDir()) {
        case 0: spears[i].getSprite()->setPosition(spears[i].getSprite()->getPosition().x, spears[i].getSprite()->getPosition().y+SPEED_SPEAR); break;
        case 1: spears[i].getSprite()->setPosition(spears[i].getSprite()->getPosition().x, spears[i].getSprite()->getPosition().y-SPEED_SPEAR); break;
        case 2: spears[i].getSprite()->setPosition(spears[i].getSprite()->getPosition().x+SPEED_SPEAR, spears[i].getSprite()->getPosition().y); break;
        case 3: spears[i].getSprite()->setPosition(spears[i].getSprite()->getPosition().x-SPEED_SPEAR, spears[i].getSprite()->getPosition().y); break;
      }
    }
    else {
      spears[i].setDir(std::rand()%4);
      delaySpear += deltatime;
      if (delaySpear >= sf::seconds(SPEAR_RATE)) {
        delaySpear = sf::Time::Zero;
        switch (spears[i].getDir()) {
          case 0: spears[i].getSprite()->setRotation(-90); spears[i].getSprite()->setPosition(WIN_X/2 - 8, -64); break;
          case 1: spears[i].getSprite()->setRotation(90); spears[i].getSprite()->setPosition(WIN_X/2 + 8, WIN_Y); break;
          case 2: spears[i].getSprite()->setRotation(180); spears[i].getSprite()->setPosition(0, WIN_Y/2 + 8); break;
          case 3: spears[i].getSprite()->setRotation(0); spears[i].getSprite()->setPosition(WIN_X, WIN_Y/2 - 8); break;
        }
      }
    }

    int x = spears[i].getSprite()->getPosition().x;
    int y = spears[i].getSprite()->getPosition().y;
    if (x < 0 -64 || x > WIN_X || y < 0-64 || y > WIN_Y) { spears[i].setDir(-1); spears[i].getSprite()->setPosition(-128,-128);}

    if (greenEmeraldofHeart.getGlobalBounds().intersects(spears[i].getSprite()->getGlobalBounds())) {
      if (spears[i].getDir() == myDir) {
        if (puntos <= 65535-10) puntos += 10;
        SPEED_SPEAR = (((SPEED_SPEAR + 0.08) > 10)? 10 : (SPEED_SPEAR + 0.08));
        SPEAR_RATE -= 0.01;
        if (SPEAR_RATE < 0.1) SPEAR_RATE = 0.1;
      }
      else
        if (puntos >= 5) puntos -= 5;
      spears[i].setDir(-1);
      spears[i].getSprite()->setPosition(-128,-128);
    }
  }

  std::stringstream sstrm;
  sstrm << "Score: " << puntos;
  score->setString(sstrm.str());

  greenEmeraldofHeart.update(deltatime);
}

void Undyne::render(sf::Time deltatime) {
  for (unsigned int i = 0; i < spears.size(); i++) {
    m_window->draw((*spears[i].getSprite()));
  }
  greenEmeraldofHeart.render(m_window);
  m_window->draw(*score);
}
