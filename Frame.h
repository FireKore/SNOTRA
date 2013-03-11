#ifndef __FRAME_H__
#define __FRAME_H__

#include <memory>
#include "Header.h"

class Frame {
 public:
  Frame();
  Frame(std::shared_ptr<Frame>, Header);
  virtual ~Frame();
  Header getHeader();
  void setHeader(Header);
  std::shared_ptr<Frame> getData();
  void setData(std::shared_ptr<Frame>);

 private:
  std::shared_ptr<Frame> data;
  Header header;

};

#endif
