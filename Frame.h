#ifndef __FRAME_H__
#define __FRAME_H__

#include "Header.h"

class Frame {
 public:
  Frame();
  Frame(const Frame&);
  Frame(Frame*, Header);
  virtual ~Frame();
  Header getHeader();
  void setHeader(Header);
  Frame* getData();
  void setData(Frame*);

 private:
  Frame* data;
  Header header;

};

#endif
