#ifndef __NETWORKINTERFACE_H__
#define __NETWORKINTERFACE_H__

#include <memory>
#include "Mac.h"
#include "Ip.h"
#include "Frame.h"
#include "Header.h"
#include "DataLinkHeader.h"
#include "NetworkHeader.h"

class NetworkInterface {
 public:
  NetworkInterface();
  NetworkInterface(Mac, std::shared_ptr<Ip>);
  virtual ~NetworkInterface();
  Mac getMac();
  void setMac(Mac);
  std::shared_ptr<Ip> getIp();
  void setIp(std::shared_ptr<Ip>);
  std::shared_ptr<Frame> receiveFrame(std::shared_ptr<Frame>);
  std::shared_ptr<Frame> createFrame(std::shared_ptr<Frame>);

 private:
  Mac mac;
  std::shared_ptr<Ip> ip;

};

#endif
