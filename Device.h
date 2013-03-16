#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <list>
#include <memory>
#include "Frame.h"

class Wire;
class Frame;

class Device {
 public:
  Device();
  virtual ~Device();
  std::list<std::shared_ptr<Frame>> getAllFrameHistory();
  virtual void receiveFrame(std::shared_ptr<Frame>);
  virtual void sendFrame(std::shared_ptr<Frame>) = 0;

 private:
  std::list<std::shared_ptr<Frame>> frameHistory;

  void addFrameToHistory(std::shared_ptr<Frame>);

};

#endif
