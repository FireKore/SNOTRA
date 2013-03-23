#include "Ipv4.h"

Ipv4::Ipv4() {
}

Ipv4::Ipv4(std::string address_) {
  unsigned int pos = 0;
  int temp;
  std::string buffer;
  std::transform(address_.begin(), address_.end(), address_.begin(), ::toupper);
  while(pos < address_.length()) {
    buffer = this->getSubstring(address_, pos);
    pos += buffer.length() + 1;
    std::istringstream iss(buffer);
    iss >> temp;
    Ip::addCharToAddress((char)temp);
  }
}

Ipv4::~Ipv4() {
}

std::string Ipv4::getSubstring(std::string str, int pos) {
  return str.substr(pos, str.find('.', pos) - pos);
}

std::string Ipv4::toString() const {
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

std::string Ipv4::toStringFull() const {
  return toString() + '/' + getMask().toString();
}

std::list<unsigned char> Ipv4::getNetwork() const {
  std::list<unsigned char> result;
  int i = 0;
  for(std::list<unsigned char>::iterator it = getAddress().begin(); it != getAddress().end(); it++, i++) {
    result.push_back(*it & getMask().getCharInPosition(i));
  }
  return result;
}
