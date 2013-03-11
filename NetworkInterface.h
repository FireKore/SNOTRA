#ifndef __NETWORKINTERFACE_H__
#define __NETWORKINTERFACE_H__

#include "Mac.h"
#include "Ip.h"
#include "MacTable.h"
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

 private:
  Mac mac;
  Ip* ip;
  MacTable macTable; // déplacer dans le Switch. Voir cahier.

};

#endif
