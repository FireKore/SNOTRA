#include "Ip.h"

Ip::Ip() {
}

Ip::Ip(std::string address_) {
  unsigned int pos = 0;
  int temp;
  std::string buffer;
  std::transform(address_.begin(), address_.end(), address_.begin(), ::toupper);
  while(pos < address_.length()) {
    buffer = this->getSubstring(address_, pos);
    pos += buffer.length() + 1;
    std::istringstream iss(buffer);
    iss >> temp;
    address.push_back((char)temp);
  }
}

Ip::~Ip() {
}

std::list<unsigned char> Ip::getAddress() {
  return address;
}

Mask Ip::getMask() {
  return mask;
}

void Ip::setMask(Mask mask_) {
  mask = mask_;
}

bool operator==(Ip ip1, Ip ip2) {
  for(std::list<unsigned char>::iterator it1 = ip1.getAddress().begin(), it2 = ip2.getAddress().begin(); it1 != ip1.getAddress().end(), it2 != ip2.getAddress().end(); it1++, it2++) {
    if(*it1 != *it2) {
      return false;
    }
  }
  return true;
}


std::string Ip::toString() {
  return 0;
}

std::string Ip::toStringFull() {
  return 0;
}

std::list<unsigned char> Ip::getNetwork() {
  return (std::list<unsigned char>)0;
}

std::string Ip::getSubstring(std::string str, int i) {
  return 0;
}
