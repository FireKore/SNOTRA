#ifndef __HEADER_H__
#define __HEADER_H__

#include "enum.h"

class Header {
 public:
  Header();
  Header(HeaderType, bool);
  virtual ~Header();
  HeaderType getType();
  void setType(HeaderType);
  bool getIsAnswer();
  void setIsAnswer(bool);

 private:
  HeaderType type;
  bool isAnswer;

};

#endif
