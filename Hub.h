#ifndef __HUB_H__
#define __HUB_H__

#include <memory>
#include <list>
#include "Device.h"
#include "Frame.h"

class Hub : public Device {
 public:
  Hub();
  virtual ~Hub();
  void receiveFrame(std::shared_ptr<Frame>, int, int);
  void sendFrame(std::shared_ptr<Frame>);

 private:

};

#endif
