#ifndef __NETWORKHEADER_H__
#define __NETWORKHEADER_H__

#include "Ip.h"

class NetworkHeader : public Header {
 public:
  NetworkHeader();
  NetworkHeader(NetworkHeader);
  virtual ~NetworkHeader();
  Ip* getSource();
  void setSource(Ip*);
  Ip* getDestination();
  void setDestination(Ip*);
  int getTimeToLive();
  void setTimeToLive(int);

 private:
  Ip* source;
  Ip* destination;
  int timeToLive;

};

#endif
