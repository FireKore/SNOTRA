#include "Ipv4.h"

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

bool Ipv4::isSameNetwork(Ip ip) {
  //TODO
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
