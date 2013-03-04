#ifndef __WIRE_H__
#define __WIRE_H__

#include "Frame.h"

class Device;

class Wire {
 public:
  Wire();
  Wire(Device*, Device*);
  virtual ~Wire();
  Device* getHead();
  void setHead(Device*);
  Device* getTail();
  void setTail(Device*);

  void sendFrame(Frame*);

 private:
  Device* head;
  Device* tail;

};

#endif
