#include "Mac.h"

Mac::Mac() {
}

Mac::~Mac() {
}

Mac::Mac(std::string address_) {
  unsigned int pos = 0;
  int temp;
  std::string buffer;
  std::transform(address_.begin(), address_.end(), address_.begin(), ::toupper);
  while (pos < address_.length()) {
    buffer = this->getSubstring(address_, pos);
    pos += buffer.length() + 1;
    std::istringstream iss(buffer);
    iss >> std::hex >> temp;
    address.push_back((char)temp);
  }
}

std::string Mac::getSubstring(std::string str, int pos) {
  return str.substr(pos, str.find('.', pos) - pos);
}

std::list<unsigned char> Mac::getAddress() {
  return address;
}

std::string Mac::toString() {
  std::string result;
  int first = 0, second = 0;
  for(std::list<unsigned char>::iterator it = getAddress().begin(); it != getAddress().end();) {
    first = *it / 16;
    second = *it % 16;
    result += toHex(first);
    result += toHex(second);
    it++;
    if(it != getAddress().end()) {
      result += ':';
    }
  }
  return result;
}

bool operator==(Mac mac1, Mac mac2) {
  for(std::list<unsigned char>::iterator it1 = mac1.getAddress().begin(), it2 = mac2.getAddress().begin(); it1 != mac1.getAddress().end(), it2 != mac2.getAddress().end(); it1++, it2++) {
    if(*it1 != *it2) {
      return false;
    }
  }
  return true;
}

char Mac::toHex(int i) {
  if(i < 10) {
    return (char)i;
  }
  else {
    switch(i) {
    case(10):
      return 'A';
      break;
    case(11):
      return 'B';
      break;
    case(12):
      return 'C';
      break;
    case(13):
      return 'D';
      break;
    case(14):
      return 'E';
      break;
    case(15):
      return 'F';
      break;
    default:
      return '0';
    }
  }
}
