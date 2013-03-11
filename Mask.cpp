#include "Mask.h"

Mask::Mask() {
}

Mask::Mask(int value_) {
  value = value_;
}

Mask::~Mask() {
}

std::string Mask::toString() {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

unsigned char Mask::getCharInPosition(int i) {
  unsigned char result;
  for(int j = 0; ((j < 8) && (j < result - 8*i)); j++) {
    result = result | (1u << (7-j));
  }
  return result;
}
