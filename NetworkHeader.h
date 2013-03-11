#ifndef __NETWORKHEADER_H__
#define __NETWORKHEADER_H__

#include "Ip.h"
#include "Header.h"
#include "enum.h"

class NetworkHeader : public Header {
 public:
  NetworkHeader();
  NetworkHeader(Ip, Ip, int, Protocole);
  virtual ~NetworkHeader();
  Ip getSource();
  void setSource(Ip);
  Ip getDestination();
  void setDestination(Ip);
  int getTimeToLive();
  void setTimeToLive(int);
  Protocole getProtocole();
  void setProtocole(Protocole);

 private:
  Ip source;
  Ip destination;
  int timeToLive;
  Protocole protocole;

};

#endif
