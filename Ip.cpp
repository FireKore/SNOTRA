#include "Ip.h"

Ip::Ip() {
}

Ip::Ip(const Ip& ip) : address(ip.address), mask(ip.mask) {
}

Ip::Ip(std::list<unsigned char> address_) {
  address = address_;
}

Ip::~Ip() {
}

std::list<unsigned char> Ip::getAddress() const {
  return address;
}

void Ip::addCharToAddress(unsigned char chr) {
  address.push_back(chr);
}

Mask Ip::getMask() const {
  return mask;
}

void Ip::setMask(Mask mask_) {
  mask = mask_;
}

bool Ip::operator==(const Ip& other) const{
  for(std::list<unsigned char>::const_iterator it1 = address.begin(), it2 = other.getAddress().begin(); it1 != address.end(), it2 != other.getAddress().end(); it1++, it2++) {
    if(*it1 != *it2) {
      return false;
    }
  }
  return true;
}

bool Ip::operator<(const Ip& other) const{
  for(std::list<unsigned char>::const_iterator it1 = address.begin(), it2 = other.getAddress().begin(); it1 != address.end(), it2 != other.getAddress().end(); it1++, it2++) {
    if(*it1 != *it2) {
      return *it1 < *it2;
    }
  }
  return true;
}
