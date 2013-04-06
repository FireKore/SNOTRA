#ifndef __NETWORKINTERFACE_H__
#define __NETWORKINTERFACE_H__

#include <memory>
#include <string>
#include <vector>
#include "Mac.h"
#include "Ip.h"
#include "Wire.h"
#include "Frame.h"
#include "Header.h"
#include "DataLinkHeader.h"
#include "NetworkHeader.h"

class Wire;
class Frame;

class NetworkInterface {
 public:
  NetworkInterface();
  NetworkInterface(std::string, Mac = Mac("00:00:00:00:00:00"), std::shared_ptr<Ip> = 0, bool = true);
  virtual ~NetworkInterface();
  Mac getMac() const;
  void setMac(Mac);
  std::shared_ptr<Ip> getIp() const;
  void setIp(std::shared_ptr<Ip>);
  bool getIsUp() const;
  void setIsUp(bool);
  std::string getName() const;
  void setName(std::string);
  std::vector<Wire> getWire() const;
  void connectWire(Wire);
  void disconnectWire(int);
  std::shared_ptr<Frame> receiveFrame(std::shared_ptr<Frame>);
  void sendFrame(std::shared_ptr<Frame>, int);
  void createFrame(std::shared_ptr<Frame>, Mac, int);
  int getNumberOfWires() const;

 private:
  Mac mac;
  std::shared_ptr<Ip> ip;
  bool isUp;
  std::string name;
  std::vector<Wire> wires;

};

#endif
