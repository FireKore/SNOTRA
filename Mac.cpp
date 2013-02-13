#include "Mac.h"

Mac::Mac(std::string str) {
  int pos = 0, temp;
  std::string buffer;
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  for (int i = 0; i < 6; i++) {
    buffer = str.substr(pos, str.find(':', pos) - pos);
    pos += buffer.length() + 1;
    std::istringstream iss(buffer);
    iss >> std::hex >> temp;
    address[i] = (char)temp;
  }
}

Mac::Mac(unsigned char* address_) {
  for(int i = 0; i < 6; i++) {
    address[i] = address_[i];
  }
}

unsigned char* Mac::getAddress() {
  return address;
}

void Mac::print() {
  int first = 0, second = 0;
  for (int i = 0; i < 5; i++) {
    first = address[i] / 16;
    second = address[i] % 16;
    std::cout << std::hex << first << second << ':';
  }
  first = (int)address[5] / 16;
  second = (int)address[5] % 16;
  std::cout << first << second << std::dec << std::endl;
}

bool Mac::isEqual(Mac mac) {
  for(int i = 0; i < 6; i++) {
    if(address[i] != mac.address[i]) {
      return false;
    }
  }
  return true;
}
