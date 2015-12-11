#include "Utils/TextMaker.hpp"

void TextMaker::setFont (std::string filename) {
  this->m_font.loadFromFile(filename);
}

sf::Text* TextMaker::createText () {
  sf::Text* texto = new sf::Text();
  texto->setFont(this->m_font);
  return texto;
}
