#include "Mask.h"

Mask::Mask(int mask_) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; ((j < 8) && (j < mask[i] - 8*i)); j++) {
      mask[i] = mask[i] | (1u << (7-j));
    }
  }
}

unsigned char* Mask::getAllMask() {
  return mask;
}

unsigned char Mask::getMask(int i) {
  return mask[i];
}

std::ostream& operator<<(std::ostream& flux, Mask& mask) {
  int c = 0;
  for(int i = 0; i < 3; i++) {
    int temp = (int)mask.getMask(i);
    while(temp != 0) {
      c += (temp & 1L);
      temp >>= 1;
    }
  }
  flux << '/' << c;
  return flux;
}
