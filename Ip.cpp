#include "Ip.h"

Ip::Ip() {
}

Ip::Ip(std::string address_) {
  int pos = 0, temp;
  std::string buffer;
  std::transform(address_.begin(), address_.end(), address_.begin(), ::toupper);
  while(pos < address_.length()) {
    buffer = this.getSubstring(address_, pos);
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
  return Mask;
}

void Ip::setMask(Mask mask_) {
  mask = mask_;
}

std::string Ip::toString() {
}

std::string Ip::toStringFull() {
}

bool Ip::isSameNetwork(Ip ip) {
  //TODO
  return true;
}

std::list<unsigned char> Ip::getNetwork() {
}

bool operator==(Ip ip1, Ip ip2) {
  for(std::list<unsigned char>::iterator it1 = ip1.getAddress.begin(), std::list<unsigned char>::iterator it2 = ip2.getAddress.begin(); it1 != ip1.getAddress.end(), it2 != ip2.getAddress.end(); it1++, it2++) {
    if(*it1 != *it2) {
      return false;
    }
  }
  return true;
}
