#ifndef __NETWORKINTERFACE_H__
#define __NETWORKINTERFACE_H__

#include <memory>
#include "Mac.h"
#include "Ip.h"
#include "Frame.h"
#include "Device.h"

class NetworkInterface {
 public:
  NetworkInterface();
  NetworkInterface(Mac, std::shared_ptr<Ip>, std::shared_ptr<Device>);
  virtual ~NetworkInterface();
  Mac getMac();
  void setMac(Mac);
  std::shared_ptr<Ip> getIp();
  void setIp(std::shared_ptr<Ip>);
  std::shared_ptr<Device> getNeighbourg();
  void setNeighbourg(std::shared_ptr<Device>);

 private:
  Mac mac;
  std::shared_ptr<Ip> ip;
  std::shared_ptr<Device> neighbourg;

};

#endif
