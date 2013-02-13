#include "Ip.h"

Ip::Ip(std::string str, int mask_) {
  mask = mask_;
  int pos = 0;
  std::string buffer;
  int temp;
  for (int i = 0; i < 4; i++) {
    buffer = str.substr(pos, str.find('.', pos) - pos);
    pos += buffer.length() + 1;
    std::istringstream iss(buffer);
    iss >> temp;
    address[i] = (char)temp;
  }
}

Ip::Ip(unsigned char* address_, int mask_) {
  mask = mask_;
  for(int i = 0; i<4; i++) {
    address[i] = address_[i];
  }
}

unsigned char* Ip::getAddress() {
  return address;
}

unsigned char Ip::getMask() {
  return (unsigned char)mask;
}

void Ip::print() {
  for (int i = 0; i < 3; i++) {
    std::cout << (int)address[i] << '.';
  }
  std::cout << (int)address[3] << " /" << mask << std::endl;
}

bool Ip::isEqual(Ip ip) {
  for(int i = 0; i < 4; i++) {
    if(address[i] != ip.address[i]) {
      return false;
    }
  }
  return true;
}

bool Ip::isSameNetwork(Ip ip) {
    for(int i = 0; i < 4; i++) {
      if ((address[i] & this->convertMaskInChar(i)) != (ip.address[i] & ip.convertMaskInChar(i))) {
      return false;
    }
  }
  return true;
}

unsigned char Ip::convertMaskInChar(int i) {
  unsigned char cMask = 0;
  for(int j = 0; ((j < 8) && (j < mask - 8*i)); j++) {
    cMask = cMask | (1u << (7-j));
  }
  return cMask;
} 
