#ifndef __ARPFRAME_H__
#define __ARPFRAME_H__

#include "NetworkFrame.h"

class ARPFrame : public NetworkFrame {
 public:
  ARPFrame();
  virtual ~ARPFrame();
  Mac getMacSource();
  void setMacSource(Mac);
  Mac getMacDest();
  void setMacDest(Mac);

 private:
  Mac macSource;
  Mac macDest;

};

#endif
