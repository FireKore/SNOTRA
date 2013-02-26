#ifndef __IP_H__
#define __IP_H__

class Ip {
 public:
  Ip();
  virtual ~Ip();
  virtual unsigned char* getAllAddress() = 0;
  virtual unsigned char getAddress(int) = 0;
};

#endif
