#ifndef __MAC_H__
#define __MAC_H__

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <list>

class Mac {
 public:
  Mac();
  Mac(std::string);
  virtual ~Mac();
  std::list<unsigned char> getAddress();
  std::string toString();
  friend bool operator==(Mac, Mac);

 private:
  std::list<unsigned char> address;

  std::string getSubstring(std::string, int);
  char toHex(int);

};

#endif
