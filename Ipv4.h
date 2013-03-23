#ifndef __IPV4_H__
#define __IPV4_H__

#include "Ip.h"

class Ipv4 : public Ip{
 public:
  Ipv4();
  Ipv4(std::string);
  virtual ~Ipv4();
  virtual std::string toString() const;
  virtual std::string toStringFull() const;
  virtual std::list<unsigned char> getNetwork() const;
  virtual std::string getSubstring(std::string, int);

 protected:

 private:

};

#endif
