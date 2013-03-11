#include "Ipv4.h"

Ipv4::Ipv4() {
}

Ipv4::~Ipv4() {
}

std::string Ipv4::getSubstring(std::string str, int pos) {
  return str.substr(pos, str.find('.', pos) - pos);
}

std::string Ipv4::toString() {
  std::string result;
  for(std::list<unsigned char>::iterator it = getAddress().begin(); it != getAddress().end();) {
    result += (int)*it;
    it++;
    if(it != getAddress().end()) {
      result += '.';
    }
  }
  return result;
}

std::string Ipv4::toStringFull() {
  return toString() + '/' + getMask().toString();
}

bool Ipv4::isSameNetwork(Ipv4 ip) {
  int i = 0;
  for(std::list<unsigned char>::iterator it1 = getAddress().begin(), it2 = ip.getAddress().begin(); it1 != getAddress().end(), it2 != ip.getAddress().end(); it1++, it2++) {
    if((*it1 & getMask().getCharInPosition(i)) != (*it2 & getMask().getCharInPosition(i))) {
      return false;
    }      
    i++;
  }
  return true;
}

std::list<unsigned char> Ipv4::getNetwork() {
  std::list<unsigned char> result;
  int i = 0;
  for(std::list<unsigned char>::iterator it = getAddress().begin(); it != getAddress().end(); it++, i++) {
    result.push_back(*it & getMask().getCharInPosition(i));
  }
  return result;
}
