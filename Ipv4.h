#ifndef __IPV4_H__
#define __IPV4_H__

#include <string>
#include <iostream>
#include <sstream>
#include "Ip.h"
#include "Mask.h"

class Ipv4 {
 public:
  Ipv4();
  Ipv4(std::string);
  unsigned char* getAllAddress();
  unsigned char getAddress(int);
  friend std::ostream& operator<<(std::ostream&, Ipv4&);
  friend bool operator==(Ipv4, Ipv4);
  bool isSameNetwork(Ipv4, Mask);
  friend Ipv4 operator+(Ipv4, Mask);
  Ipv4 operator=(Ipv4);

 private:
  unsigned char address[4];

  void setAddress(int, unsigned char);
};

#endif
