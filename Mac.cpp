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

unsigned char* Mac::getAllAddress() {
  return address;
}

unsigned char Mac::getAddress(int i) {
  return address[i];
}

std::ostream& operator<<(std::ostream& flux, Mac& mac) {
  int first = 0, second = 0;
  for (int i = 0; i < 5; i++) {
    first = mac.getAddress(i) / 16;
    second = mac.getAddress(i) % 16;
    flux << std::hex << first << second << ':';
  }
  first = (int)mac.getAddress(5) / 16;
  second = (int)mac.getAddress(5) % 16;
  flux << first << second << std::dec;
  return flux;
}

bool operator==(Mac mac1, Mac mac2) {
  for(int i = 0; i < 6; i++) {
    if(mac1.getAddress(i) != mac2.getAddress(i)) {
      return false;
    }
  }
  return true;
}
