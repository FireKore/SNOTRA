#ifndef __NETFRAME_H__
#define __NETFRAME_H__

#include "Frame.h"
#include "TransportFrame.h"
#include "enum.h"

class NetworkFrame : public Frame {
 public:
  Ip* getIpSource();
  void setIpSource(Ip*);
  Ip* getIpDest();
  void setIpDest(Ip*);
  int getTTL();
  void setTTL(int);
  Protocole getProtocole();
  void setProtocole(Protocole);
  TransportFrame getData();
  void setData(TransportFrame);

  void decrementTTL();
  bool isAlive();

 private:
  Ip* ipSource;
  Ip* ipDest;
  int ttl;
  Protocole protocole;
  TransportFrame data;

};

#endif
