#ifndef __FRAME_H__
#define __FRAME_H__

#include "Mac.h"
#include "Ip.h"
#include "enum.h"

class Frame {
 public:
  Frame();
  virtual ~Frame();
  virtual FrameType getFrameType() = 0;
  virtual Protocole getProtocole() = 0;
  virtual Ip* getSourceIp() = 0;
  virtual Ip* getDestIp() = 0;
  virtual Mac getSourceMac() = 0;
  virtual Mac getDestMac() = 0;

 private:

};

#endif
