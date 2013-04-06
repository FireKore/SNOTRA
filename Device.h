#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <list>
#include <memory>
#include <vector>
#include <sstream>
#include "Frame.h"
#include "NetworkInterface.h"

class Frame;
class Wire;
class NetworkInterface;

class Device {
 public:
  Device();
  virtual ~Device();
  std::list<std::shared_ptr<Frame>> getAllFrameHistory() const;
  std::vector<NetworkInterface> getNetworkInterfaces() const;
  void sendFrameBroadcast(std::shared_ptr<Frame>);
  void sendFrameUnicast(std::shared_ptr<Frame>, int, int);
  virtual void receiveFrame(std::shared_ptr<Frame>, int, int);
  std::shared_ptr<Frame> giveFrameToInterface(std::shared_ptr<Frame>, int);
  virtual void sendFrame(std::shared_ptr<Frame>) = 0;
  void addNetworkInterface(std::string, Mac, std::shared_ptr<Ip>, bool);
  virtual void connectNeighbour(std::shared_ptr<Device>, int, int, int, int);
  void disconnectNeighbour(int);
  void activateNetworkInterface(int);
  void desactivateNetworkInterface(int);

 private:
  std::list<std::shared_ptr<Frame>> frameHistory;
  std::vector<NetworkInterface> networkInterfaces;

  void addFrameToHistory(std::shared_ptr<Frame>);

};

#endif
