#ifndef __MAC_H__
#define __MAC_H__

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class Mac {
 public:
  Mac(std::string);
  unsigned char* getAllAddress();
  unsigned char getAddress(int);
  friend std::ostream& operator<<(std::ostream&, Mac&);
  friend bool operator==(Mac, Mac);

 private:
  unsigned char address[6];

};

#endif
