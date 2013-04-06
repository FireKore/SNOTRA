#ifndef __NETWORKHEADER_H__
#define __NETWORKHEADER_H__

#include <memory>
#include "Ip.h"
#include "Header.h"
#include "enum.h"

class NetworkHeader : public Header {
 public:
  NetworkHeader();
  NetworkHeader(std::shared_ptr<Ip>, std::shared_ptr<Ip>, int, Protocole, bool);
  virtual ~NetworkHeader();
  std::shared_ptr<Ip> getSource();
  void setSource(std::shared_ptr<Ip>);
  std::shared_ptr<Ip> getDestination();
  void setDestination(std::shared_ptr<Ip>);
  int getTimeToLive();
  void decreaseTimeToLive();
  void setTimeToLive(int);
  Protocole getProtocole();
  void setProtocole(Protocole);

 private:
  std::shared_ptr<Ip> source;
  std::shared_ptr<Ip> destination;
  int timeToLive;
  Protocole protocole;

};

#endif
