#ifndef __ETHFRAME_H__
#define __ETHFRAME_H__

#include "Frame.h"
#include "NetworkFrame.h"
#include "enum.h"

class EthernetFrame : public Frame {
 public:
  Mac getMacSource();
  void setMacSource(Mac);
  Mac getMacDest();
  void setMacDest(Mac);
  FrameType getFrameType();
  void setFrameType(FrameType);
  NetworkFrame getData();
  void setData(NetworkFrame);

 private:
  Mac macSource;
  Mac macDest;
  FrameType frameType;
  NetworkFrame data;

};

#endif
