#include "Music/SoundPlayer.hpp"

void SoundPlayer::play (std::string filename) {
  if (!this->m_buffer.loadFromFile(filename))
    return;

  this->m_sound.setBuffer(this->m_buffer);
  this->m_sound.play();
}

void SoundPlayer::pause (bool pause) {
  if (pause) this->m_sound.pause();
  else this->m_sound.play();
}

void SoundPlayer::stop () {
  this->m_sound.stop();
}

void SoundPlayer::setVolume (float volume) {
  this->m_volume = volume;
  this->m_sound.setVolume(volume);
}

void SoundPlayer::setPitch (float pitch) {
  this->m_pitch = pitch;
  this->m_sound.setPitch(pitch);
}
