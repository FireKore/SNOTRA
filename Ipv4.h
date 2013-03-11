#ifndef __IPV4_H__
#define __IPV4_H__

#include "Ip.h"

class Ipv4 : public Ip{
 public:
  Ipv4();
  Ipv4(std::string);
  virtual ~Ipv4();
  virtual std::string getSubstring(std::string, int);
  virtual std::string toString();
  virtual std::string toStringFull();
  virtual bool isSameNetwork(Ipv4);
  virtual std::list<unsigned char> getNetwork();

 private:

};

#endif
