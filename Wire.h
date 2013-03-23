#ifndef __WIRE_H__
#define __WIRE_H__

#include <memory>
#include "Frame.h"
#include "Device.h"

class Device;
class Frame;

class Wire {
 public:
  Wire();
  Wire(std::shared_ptr<Device>, int, std::shared_ptr<Device>, int);
  virtual ~Wire();
  std::shared_ptr<Device> getHead() const;
  void setHead(std::shared_ptr<Device>);
  int getHeadPort() const;
  void setHeadPort(int);
  std::shared_ptr<Device> getTail() const;
  void setTail(std::shared_ptr<Device>);
  int getTailPort() const;
  void setTailPort(int);

  void sendFrame(std::shared_ptr<Frame>);

 private:
  std::shared_ptr<Device> head;
  int headPort;
  std::shared_ptr<Device> tail;
  int tailPort;

};

#endif
