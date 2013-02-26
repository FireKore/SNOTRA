#ifndef __ICMPFRAME_H__
#define __ICMPFRAME_H__

#include "TransportFrame.h"

class ICMPFrame : public TransportFrame {
 public:
  ICMPFrame();
  virtual ~ICMPFrame();
  Ip* getSourceIp();
  void setSourceIp(Ip*);
  bool getIsRequest();
  void setIsRequest(bool);

 private:
  Ip* sourceIp;
  bool isRequest;

};

#endif
