#ifndef __SOUND_PLAYER_HPP__
#define __SOUND_PLAYER_HPP__

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class SoundPlayer {
  public:
    void play (std::string filename);
    void pause (bool pause = true);
    void stop ();
    void setVolume (float volume);
    void setPitch (float pitch);

  private:
    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
    float m_volume;
    float m_pitch;

};

#endif // __SOUND_PLAYER_HPP__
