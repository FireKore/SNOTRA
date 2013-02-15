unsigned char Ip::convertMaskInChar(int i) {
  unsigned char cMask = 0;
  for(int j = 0; ((j < 8) && (j < mask - 8*i)); j++) {
    cMask = cMask | (1u << (7-j));
  }
  return cMask;
} 

