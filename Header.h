#ifndef __HEADER_H__
#define __HEADER_H__

#include "enum.h"

class Header {
 public:
  Header();
  Header(HeaderType);
  virtual ~Header();
  HeaderType getType();
  void setType(HeaderType);

 private:
  HeaderType type;

};

#endif
