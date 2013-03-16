#ifndef __FRAME_H__
#define __FRAME_H__

#include <memory>
#include "Header.h"
#include "Device.h"

class Device;

class Frame {
 public:
  Frame();
  Frame(std::shared_ptr<Frame>, std::shared_ptr<Header>, std::shared_ptr<Device>);
  virtual ~Frame();
  std::shared_ptr<Header> getHeader();
  void setHeader(std::shared_ptr<Header>);
  std::shared_ptr<Frame> getData();
  void setData(std::shared_ptr<Frame>);
  std::shared_ptr<Device> getSourceDevice();
  void setSourceDevice(std::shared_ptr<Device>);

 private:
  std::shared_ptr<Frame> data;
  std::shared_ptr<Header> header;
  std::shared_ptr<Device> sourceDevice;

};

#endif
