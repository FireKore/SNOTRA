#include "Mask.h"

Mask::Mask() {
}

Mask::Mask(int value_) {
  value = value;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; ((j < 8) && (j < mask[i] - 8*i)); j++) {
      mask[i] = mask[i] | (1u << (7-j));
    }
  }
}

Mask::~Mask() {
}

std::string Mask::toString() {
  std::string result = value;
  return result;
}

unsigned char Mask::getCharInPosition(int i) {
  unsigned char result;
  for(int j = 0; ((j < 8) && (j < result - 8*i)); j++) {
    result = result | (1u << (7-j));
  }
  return result;
}
