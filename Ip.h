#ifndef __IP_H__
#define __IP_H__

#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include "Mask.h"

class Ip {
 public:
  Ip();
  Ip(const Ip&);
  Ip(std::string);
  Ip(std::list<unsigned char>);
  virtual ~Ip();
  std::list<unsigned char> getAddress() const;
  void addCharToAddress(unsigned char);
  Mask getMask() const;
  void setMask(Mask);
  virtual std::string toString() = 0;
  virtual std::string toStringFull() = 0;
  virtual std::list<unsigned char> getNetwork() const = 0;
  bool operator==(const Ip&) const;
  bool operator<(const Ip&) const;

 protected:
  virtual std::string getSubstring(std::string, int) = 0;

 private:
  std::list<unsigned char> address;
  Mask mask;

};

#endif
