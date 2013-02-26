#ifndef __UDPFRAME_H__
#define __UDPFRAME_H__

#include "TransportFrame.h"

class UDPFrame : public TransportFrame {
 public:
  UDPFrame();
  virtual ~UDPFrame();
  int getSourcePort();
  void setSourcePort(int);
  int getDestPort();
  void setDestPort(int);

 private:
  int sourcePort;
  int destPort;

};

#endif
