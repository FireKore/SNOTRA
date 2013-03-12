#ifndef __ARPHEADER_H__
#define __ARPHEADER_H__

#include "Mac.h"
#include "NetworkHeader.h"

class ARPHeader : public NetworkHeader {
 public:
  ARPHeader();
  ARPHeader(Ip, Ip, int, Protocole, Mac, Mac, bool);
  virtual ~ARPHeader();
  Mac getSourceMac();
  void setSourceMac(Mac);
  Mac getDestinationMac();
  void setDestinationMac(Mac);

 private:
  Mac sourceMac;
  Mac destinationMac;

};

#endif
