#ifndef __TEXT_MAKER_HPP__
#define __TEXT_MAKER_HPP__

#include <SFML/Graphics.hpp>

class TextMaker {
  private:
    sf::Font m_font;

  public:
    void setFont (std::string filename);
    sf::Text* createText();
};

#endif // __TEXT_MAKER_HPP__
