#ifndef __ARPTABLE_H__
#define __ARPTABLE_H__

#include <list>
#include "Mac.h"
#include "Ip.h"
#include "NetworkInterface.h"

class ARPTableLine {
 public:
  ARPTableLine();
  ARPTableLine(Ip*, Mac);
  virtual ~ARPTableLine();
  Ip* getIp();
  void setIp(Ip*);
  Mac getMac();
  void setMac(Mac);
  NetworkInterface getNetworkInterface();
  void setNetworkInterface(NetworkInterface);

 private:
  Ip* ip;
  Mac mac;
  //dégager interface et ajouter la durée de vie

};

class ARPTable {
 public:
  ARPTable();
  virtual ~ARPTable();
  std::list<ARPTableLine> getAllLines();
  ARPTableLine getLineByIp(Ip* ip);
  void addLine(ARPTableLine);

 private:
  std::list<ARPTableLine> arpTable;

};

#endif
