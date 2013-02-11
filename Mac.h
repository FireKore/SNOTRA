#ifndef __MAC_H__
#define __MAC_H__

#include <cctype>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class Mac {
 public:
  Mac(std::string str);
  Mac(unsigned char* address);
  unsigned char* getAddress();
  void print();
  bool isEqual(Mac mac);

 private:
  unsigned char address[6];

};

#endif
