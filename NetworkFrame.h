#ifndef __NETFRAME_H__
#define __NETFRAME_H__

#include "Frame.h"
#include "TransportFrame.h"
#include "enum.h"

class NetworkFrame : public Frame {
 public:
  NetworkFrame();
  virtual ~NetworkFrame();
  Ip* getSourceIp();
  void setSourceIp(Ip*);
  Ip* getDestIp();
  void setDestIp(Ip*);
  int getTTL();
  void setTTL(int);
  Protocole getProtocole();
  void setProtocole(Protocole);
  TransportFrame getData();
  void setData(TransportFrame);

  void decrementTTL();
  bool isAlive();

 private:
  Ip* sourceIp;
  Ip* destIp;
  int ttl;
  Protocole protocole;
  TransportFrame data;

};

#endif
