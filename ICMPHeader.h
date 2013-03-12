#ifndef __ICMPHEADER_H__
#define __ICMPHEADER_H__

#include <time.h>
#include "TransportHeader.h"
#include "Ip.h"

class ICMPHeader : public TransportHeader {
 public:
  ICMPHeader();
  ICMPHeader(Ip, bool);
  virtual ~ICMPHeader();
  time_t getTime();
  void setTime(time_t);
  void setTimeNow();
  Ip getSourceIp();
  void setSourceIp(Ip);
  bool getIsAnswer();
  void setIsAnswer(bool);

 private:
  time_t creationTime;
  Ip sourceIp;
  bool isAnswer;

};

#endif
