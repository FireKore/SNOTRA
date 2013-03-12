#ifndef __SWITCH_H__
#define __SWITCH_H__

#include <memory>
#include "Frame.h"

class Switch : public Device {
 public:
  Switch();
  virtual ~Switch();
  void receiveFrame(std::shared_ptr<Frame>);
  void sendFrame(std::shared_ptr<Frame>);

 private:

};

#endif
