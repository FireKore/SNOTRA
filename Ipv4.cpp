#include "Ipv4.h"

Ipv4::Ipv4(std::string str) {
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

unsigned char* Ipv4::getAllAddress() {
  return address;
}

unsigned char Ipv4::getAddress(int i) {
  return address[i];
}

std::ostream& operator<<(std::ostream& flux, Ipv4& ip) {
  for (int i = 0; i < 3; i++) {
    flux << (int)ip.getAddress(i) << '.';
  }
  flux << (int)ip.getAddress(3);
  return flux;
}

bool operator==(Ipv4 ip1, Ipv4 ip2) {
    for(int i = 0; i < 4; i++) {
      if(ip1.getAddress(i) != ip2.getAddress(i)) {
	return false;
      }
    }
    return true;
}

bool Ipv4::isSameNetwork(Ipv4 ip, Mask mask) {
    for(int i = 0; i < 4; i++) {
      if ((address[i] & mask.getMask(i)) != (ip.getAddress(i) & mask.getMask(i))) {
      return false;
    }
  }
  return true;
}
