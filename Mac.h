#ifndef __MAC_H__
#define __MAC_H__

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class Mac {
 public:
  Mac(std::string);
  Mac();
  unsigned char* getAllAddress();
  unsigned char getAddress(int);
  friend std::ostream& operator<<(const std::ostream&, const Mac&);
  friend bool operator==(Mac, Mac);
  Mac operator=(Mac);

 private:
  unsigned char address[6];

  void setAddress(int, unsigned char);

};

#endif
