#ifndef __ETHFRAME_H__
#define __ETHFRAME_H__

#include "Frame.h"
#include "NetworkFrame.h"
#include "enum.h"

class EthernetFrame : public Frame {
 public:
  EthernetFrame();
  virtual ~EthernetFrame();
  Mac getSourceMac();
  void setSourceMac(Mac);
  Mac getDestMac();
  void setDestMac(Mac);
  FrameType getFrameType();
  void setFrameType(FrameType);
  NetworkFrame getData();
  void setData(NetworkFrame);

 private:
  Mac sourceMac;
  Mac destMac;
  FrameType frameType;
  NetworkFrame data;

};

#endif
