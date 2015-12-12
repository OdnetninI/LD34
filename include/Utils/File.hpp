#ifndef __FILE_HPP__
#define __FILE_HPP__

#include <fstream>
#include <cstdint>

bool openBinary (std::ifstream& file, std::string filename) {
  file.open(filename, std::ios::in | std::ios::binary);
  if (file.is_open()) {
    file.seekg (0, file.beg);
    return true;
  }
  return false;
}

char readByte (std::ifstream& file) {
  if (file.eof() || !file.good()) return 0x00;
  return file.get();
}

uint8_t readByteAsUINT8 (std::ifstream& file) {
  if (file.eof() || !file.good()) return 0x00;
  return file.get();
}

uint16_t readBytesAsUINT16 (std::ifstream& file) {
  return (readByteAsUINT8(file) << 8 | readByteAsUINT8(file));
}

int8_t readByteAsINT8 (std::ifstream& file) {
  if (file.eof() || !file.good()) return 0x00;
  return file.get();
}

int16_t readBytesAsINT16 (std::ifstream& file) {
  return (readByteAsINT8(file) << 8 | readByteAsINT8(file));
}

#endif // __FILE_HPP__
