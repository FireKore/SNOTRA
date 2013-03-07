#ifndef __FRAME_H__
#define __FRAME_H__

#include "Header.h"

class Frame {
 public:
  Frame();
  Frame(Frame);
  Frame(Frame*, Header*);
  virtual ~Frame();
  FrameType getDataLevel();
  void setDataLevel(FrameType);
  Header* getHeader();
  void setHeadet(Header*);
  Frame* getData();
  void setData(Frame*);

 private:
  FrameType dataLevel;
  Header* header;
  Frame* data;

};

#endif
