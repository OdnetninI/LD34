#include "Music/MusicPlayer.hpp"

MusicPlayer::MusicPlayer () {
  this->m_volume = 100.f;
}

void MusicPlayer::play (std::string filename) {
  if (!this->m_music.openFromFile(filename))
    return;

  this->m_music.setVolume(this->m_volume);
  this->m_music.setLoop(true);
  this->m_music.play();
}

void MusicPlayer::stop () {
  this->m_music.stop();
}

void MusicPlayer::setVolume (float volume) {
  this->m_volume = volume;
  this->m_music.setVolume(this->m_volume);
}

void MusicPlayer::pause (bool pause) {
  if (pause) this->m_music.pause();
  else this->m_music.play();
}
