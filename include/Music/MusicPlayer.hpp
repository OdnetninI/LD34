#ifndef __MUSIC_PLAYER_HPP__
#define __MUSIC_PLAYER_HPP__

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class MusicPlayer {
  public:
    MusicPlayer();

    void play (std::string filename);
    void stop ();
    void pause (bool pause = true);
    void setVolume (float volume);

  private:
    sf::Music m_music;
    float m_volume;
};

#endif // __MUSIC_PLAYER_HPP__
