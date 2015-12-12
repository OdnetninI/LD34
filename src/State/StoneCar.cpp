#include "State/StoneCar.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>

StoneCar::StoneCar (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker) {
    this->m_window = window;
    this->m_eventmng = events;
    this->m_statemng = states;
    this->m_textMaker = textmaker;
    score = textmaker->createText();
    score->setCharacterSize(15);
    score->setColor(sf::Color::Black);
    score->setPosition(15,15);
    std::srand(std::time(nullptr));
    road.load("Data/Road.png");
    scrollx = 0;
    road.getSprite()->setPosition(0, 0);

    car.load("Data/Car.png");
    car.getSprite()->setPosition(20, WIN_Y/2 - 32);

    _rock.loadFromFile("Data/Rock.png");
}

StoneCar::~StoneCar () {

}

void StoneCar::update(sf::Time deltatime) {
  if (!m_eventmng->isFocused()) return;
  scrollx+=2;
  scrollx %= 82;
  road.getSprite()->setPosition(-scrollx, 0);

  if (m_eventmng->getKey(sf::Keyboard::Escape)) m_statemng->popLooped();

  keyDelay += deltatime;
  if (keyDelay >= sf::seconds(0.2)) {
    if (m_eventmng->getKey(sf::Keyboard::Up)) {car.getSprite()->setPosition(20, WIN_Y/2 - 32 - 160); keyDelay = sf::Time::Zero;}
    else if (m_eventmng->getKey(sf::Keyboard::Down)) {car.getSprite()->setPosition(20, WIN_Y/2 - 32 + 160); keyDelay = sf::Time::Zero;}
    else { car.getSprite()->setPosition(20, WIN_Y/2 - 32); keyDelay = sf::Time::Zero;}
    keyDelay -= deltatime;
  }

  for (unsigned int i = 0; i < rocas.size(); i++) {
    rocas[i].move(-rockSpeed,0);

    if (car.getGlobalBounds().intersects(rocas[i].getGlobalBounds()))
    {
      // Nunca hacer esto otra vez X2
      rocas.erase(rocas.begin() + i);
      if (i != 0)i--; // PROHIBIDO, pero funciona :D
      if (puntos >= 3) puntos -= 3;
    }
    if (rocas[i].getPosition().x < -64) {
      // Nunca hacer esto otra vez
      rocas.erase(rocas.begin() + i);
      if (i != 0)i--; // PROHIBIDO, pero funciona :D
      rockSpeed += 0.3;
      if (rockSpeed > 7) rockSpeed = 7;
      rockRate -= 0.2;
      if (rockRate < 0.8) rockRate = 0.8;
      puntos++;
    }
  }

  rockDelay += deltatime;
  if (rockDelay >= sf::seconds(rockRate)) {

    int r = std::rand()%4;
    if (r == 0) {
      sf::Sprite rock;
      rock.setTexture(_rock);
      rock.setPosition(WIN_X, WIN_Y/2 - 32 - 160);
      rocas.push_back(rock);
    }
    else if (r == 1) {
      sf::Sprite rock;
      rock.setTexture(_rock);
      rock.setPosition(WIN_X, WIN_Y/2 - 32);
      rocas.push_back(rock);
    }
    else if (r == 2) {
      sf::Sprite rock;
      rock.setTexture(_rock);
      rock.setPosition(WIN_X, WIN_Y/2 - 32 + 160);
      rocas.push_back(rock);
    }
    else {
      sf::Sprite rock;
      rock.setTexture(_rock);
      rock.setPosition(WIN_X, WIN_Y/2 - 32 - 160);
      rocas.push_back(rock);

      sf::Sprite rock1;
      rock1.setTexture(_rock);
      rock1.setPosition(WIN_X, WIN_Y/2 - 32 + 160);
      rocas.push_back(rock1);
    }

    rockDelay = sf::Time::Zero;
  }

  std::stringstream sstrm;
  sstrm << "Score: " << puntos;
  score->setString(sstrm.str());

}

void StoneCar::render(sf::Time deltatime) {
  road.render(m_window);
  for (unsigned int i = 0; i < rocas.size(); i++)
    m_window->draw(rocas[i]);
  car.render(m_window);
  m_window->draw(*score);
}
