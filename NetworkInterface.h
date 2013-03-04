#ifndef __NETWORKINTERFACE_H__
#define __NETWORKINTERFACE_H__

#include "Mac.h"
#include "Ip.h"
#include "MacTable.h"
#include "EthernetFrame.h"
#include "Frame.h"

class NetworkInterface {
 public:
  NetworkInterface();
  NetworkInterface(Mac, Ip*);
  virtual ~NetworkInterface();
  Mac getMac();
  void setMac(Mac);
  Ip* getIp();
  void setIp(Ip*);
  MacTable getMacTable();
  void setMacTable(MacTable);

  Frame* createEthernetFrame(Frame*, Mac, FrameType);
  void sendFrame(Frame*);

 private:
  Mac mac;
  Ip* ip;
  MacTable macTable;
  Device* device;

};

#endif
