#ifndef __IP_H__
#define __IP_H__

#include <list>
#include <string>
#include <sstream>
#include "Mask.h"

class Ip {
 public:
  Ip();
  Ip(std::string);
  virtual ~Ip();
  std::list<unsigned char> getAddress();
  Mask getMask();
  void setMask(Mask);
  virtual std::string toString();
  virtual std::string toStringFull();
  virtual bool isSameNetwork(Ip);
  virtual std::list<unsigned char> getNetwork();
  friend bool operator==(Ip, Ip);

 protected:
  virtual std::string getSubstring(std::string, int);

 private:
  std::list<unsigned char> address;
  Mask mask;

};

#endif
