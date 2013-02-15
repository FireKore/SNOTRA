#ifndef __MASK_H__
#define __MASK_H__

#include<iostream>

class Mask {
 public:
  Mask(int);
  unsigned char* getAllMask();
  unsigned char getMask(int);
  friend std::ostream& operator<<(std::ostream&, Mask&);

 private:
  unsigned char mask[4];
};

#endif
