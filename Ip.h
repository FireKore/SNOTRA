#ifndef __IP_H__
#define __IP_H__

class Ip {
 public:
  virtual unsigned char* getAllAddress();
  virtual unsigned char getAddress(int);
};

#endif
