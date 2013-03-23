#ifndef __ICMPHEADER_H__
#define __ICMPHEADER_H__

#include <time.h>
#include <memory>
#include "TransportHeader.h"
#include "Ip.h"

class ICMPHeader : public TransportHeader {
 public:
  ICMPHeader();
  ICMPHeader(std::shared_ptr<Ip>, bool);
  virtual ~ICMPHeader();
  time_t getTime();
  void setTime(time_t);
  void setTimeNow();
  std::shared_ptr<Ip> getSourceIp();
  void setSourceIp(std::shared_ptr<Ip>);

 private:
  time_t creationTime;
  std::shared_ptr<Ip> sourceIp;

};

#endif
