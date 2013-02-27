#ifndef __TRANSFRAME_H__
#define __TRANSFRAME_H__

#include "Frame.h"

class TransportFrame : public Frame {
 public:
  TransportFrame();
  virtual ~TransportFrame();

  FrameType getFrameType();
  Protocole getProtocole();
  Ip* getSourceIp();
  Ip* getDestIp();
  Mac getSourceMac();
  Mac getDestMac();

 private:

};

#endif
