#include "State/SplashScreen.hpp"

SplashScreen::SplashScreen (sf::RenderWindow* window, EventManager* events, StateManager* states, TextMaker* textmaker) {
  this->m_window = window;
  this->m_eventmng = events;
  this->m_statemng = states;
  this->m_textMaker = textmaker;

  counter = sf::Time::Zero;
  alpha = 0;
  BG.load("Data/Splash.png");
}

SplashScreen::~SplashScreen () {

}

void SplashScreen::update(sf::Time deltatime) {
  counter += deltatime;
  if (counter >= sf::seconds(5)) m_statemng->popLooped();

  if (counter < sf::seconds(2)) {
    alpha = ((alpha + (2000/255)+1) < 255)? alpha + (2000/255)+1 : 255;
  }
  if (counter > sf::seconds(4)) {
    alpha = ((alpha - (1000/255) -1) > 0)? alpha - (1000/255)-1 : 0;
  }
  BG.getSprite()->setColor(sf::Color(255, 255, 255, alpha));
}

void SplashScreen::render(sf::Time deltatime) {
  BG.render(m_window);
}
