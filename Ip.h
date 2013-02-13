#ifndef __IP_H__
#define __IP_H__

#include <string>
#include <iostream>
#include <sstream>

class Ip {
 public:
  Ip(std::string str, int mask);
  Ip(unsigned char* address, int mask);
  unsigned char* getAddress();
  unsigned char getMask();
  void print();
  bool isEqual(Ip ip);
  bool isSameNetwork(Ip ip);

 private:
  unsigned char address[4];
  int mask;

  unsigned char convertMaskInChar(int i);
};

#endif
