#include "State/FlowerPlant.hpp"
#include <sstream>

FlowerPlant::FlowerPlant (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker) {
    this->m_window = window;
    this->m_eventmng = events;
    this->m_statemng = states;
    this->m_textMaker = textmaker;

    score = textmaker->createText();
    score->setCharacterSize(14);
    score->setColor(sf::Color::Black);
    score->setPosition(665,25);
    puntos = 0;

    ll = 0;
    sol = 0;

    flor = nullptr;
    S.load("Data/S.png");
    S.setDimensions(64,64);
    S.setTextureDimensions(64,64);
    S.setPosition(50, 380);

    SBar.load("Data/SBAR.png");
    SBar.setDimensions(55,300);
    SBar.setTextureDimensions(55,300);
    SBar.setPosition(55, 75);

    L.load("Data/L.png");
    L.setDimensions(64,64);
    L.setTextureDimensions(64,64);
    L.setPosition(130, 380);

    LBar.load("Data/LBAR.png");
    LBar.setDimensions(55,300);
    LBar.setTextureDimensions(55,300);
    LBar.setPosition(135, 75);

    fondo.load("Data/Estados.png");
    fondo.setDimensions(400,512);
    fondo.setTextureDimensions(400,2560);
    fondo.setPosition(250,0);

    BG.load("Data/BG.png");

    Flower* FlowerBase = new Flower("Data/FlowerBasic.png",300,500,300,2500,90,75,12);

    flor = FlowerBase;
    flor->getSprite()->setPosition(300,6);
}

FlowerPlant::~FlowerPlant () {
  delete score;
}

void FlowerPlant::update(sf::Time deltatime) {
  if (!m_eventmng->isFocused()) return;
  elapsed += deltatime;
  if (elapsed >= sf::seconds(0.5)) {
    if (m_eventmng->getKey(sf::Keyboard::S)) {
      estado++;
      if (estado > 2) estado = 2;
      elapsed = sf::Time::Zero;
    }

    else if (m_eventmng->getKey(sf::Keyboard::L)) {
      estado--;
      if (estado < -2) estado = -2;
      elapsed = sf::Time::Zero;
    }

    else if (m_eventmng->getKey(sf::Keyboard::Escape))
      m_statemng->popLooped();

    else
      elapsed = elapsed - deltatime;
  }

  elapsed2 += deltatime;
  if (elapsed2 >= sf::seconds(1.5)) {

    if (estado == 0) {
      ll--; sol--;
    }

    else if (estado == 1) {
      sol+=2; ll--;
    }

    else if (estado == 2) {
      sol += 4; ll -= 3;
    }

    else if (estado == -1) {
      ll+=2; sol--;
    }

    else if (estado == -2) {
      ll += 4; sol -= 3;
    }

    elapsed2 = sf::Time::Zero;
  }

  std::stringstream sstm;
  sstm << "Score: " << puntos;
  score->setString(sstm.str());

  elapsed3 += deltatime;
  if (elapsed3 >= sf::seconds(4)) {
    if (sol == 0 || ll == 0) {
      estado = 0;
      sol = 0;
      ll = 0;
      flor->kill();
      if (puntos >= 5) puntos -= 5;
    }
    elapsed3 = sf::Time::Zero;
  }

  if (ll > 100) ll = 100;
  if (sol > 100) sol = 100;
  if (ll < 0) ll = 0;
  if (sol < 0) sol = 0;

  if ((ll > flor->getLluvia() - flor->getError() && ll < flor->getLluvia() + flor->getError()) &&
      (sol > flor->getSol() - flor->getError() && sol < flor->getSol() + flor->getError())) {
        flor->grow();
        if (puntos <= 65565-10)
          puntos += 10;
        sol = 1;
        ll = 1;
      }

  fondo.setIndex(estado+2);

  LBar.setDimensions(55, ll*3);
  LBar.setPosition(135, 375 - ll*3);
  LBar.setOffsets(0, 300 - ll*3);

  SBar.setDimensions(55, sol*3);
  SBar.setPosition(55, 375 - sol*3);
  SBar.setOffsets(0, 300 - sol*3);

  S.update(deltatime);
  SBar.update(deltatime);
  L.update(deltatime);
  LBar.update(deltatime);
  fondo.update(deltatime);
  flor->getSprite()->update(deltatime);
}

void FlowerPlant::render(sf::Time deltatime) {
  fondo.render(this->m_window);
  BG.render(this->m_window);
  S.render(this->m_window);
  SBar.render(this->m_window);
  L.render(this->m_window);
  LBar.render(this->m_window);
  flor->getSprite()->render(this->m_window);
  this->m_window->draw(*score);
}
