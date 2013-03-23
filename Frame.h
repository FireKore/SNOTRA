#ifndef __FRAME_H__
#define __FRAME_H__

#include <memory>
#include "Header.h"
#include "Device.h"

class Device;

class Frame {
 public:
  Frame();
  Frame(std::shared_ptr<Frame>, std::shared_ptr<Header>, int);
  virtual ~Frame();
  std::shared_ptr<Header> getHeader();
  void setHeader(std::shared_ptr<Header>);
  std::shared_ptr<Frame> getData();
  void setData(std::shared_ptr<Frame>);
  int getInterfaceId();
  void setInterfaceId(int);

 private:
  std::shared_ptr<Frame> data;
  std::shared_ptr<Header> header;
  int interfaceId;

};

#endif
