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

Ipv4::Ipv4() {
  for (int i = 0; i < 4; i++) {
    address[i] = 0;
  }
}

unsigned char* Ipv4::getAllAddress() {
  return address;
}

unsigned char Ipv4::getAddress(int i) {
  return address[i];
}

void Ipv4::setAddress(int i, unsigned char c) {
  address[i] = c;
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

Ipv4 operator+(Ipv4 ip, Mask mask) {
  Ipv4 temp;
  for(int i = 0; i < 4; i++) {
    temp.setAddress(i, (ip.getAddress(i) & mask.getMask(i)));
  }
  return temp;
}

Ipv4 Ipv4::operator=(Ipv4 other) {
  Ipv4 ip;
  for (int i = 0; i < 4; i++) {
    ip.setAddress(i, other.getAddress(i));
  }
  return ip;
}
