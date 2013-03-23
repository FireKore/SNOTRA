#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <list>
#include <memory>
#include <map>
#include "Frame.h"
#include "Wire.h"

class Frame;
class Wire;

class Device {
 public:
  Device();
  virtual ~Device();
  std::list<std::shared_ptr<Frame>> getAllFrameHistory() const;
  Wire getWireByNetworkInterfaceID(int) const;
  void sendFrameBroadcast(std::shared_ptr<Frame>, int);
  void sendFrameUnicast(std::shared_ptr<Frame>, int);
  virtual void receiveFrame(std::shared_ptr<Frame>, int);
  virtual void sendFrame(std::shared_ptr<Frame>) = 0;
  void connectNeighbour(std::shared_ptr<Device>, int, int);
  void disconnectNeighbour(int);

 private:
  std::list<std::shared_ptr<Frame>> frameHistory;
  std::map<int, Wire> wires;

  void addFrameToHistory(std::shared_ptr<Frame>);

};

#endif
