#ifndef __MASK_H__
#define __MASK_H__

#include <string>
#include <sstream>

class Mask {
 public:
  Mask();
  Mask(int);
  virtual ~Mask();
  std::string toString();
  unsigned char getCharInPosition(int);

 private:
  int value;
};

#endif
