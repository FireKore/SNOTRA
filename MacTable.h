#ifndef __MACTABLE_H__
#define __MACTABLE_H__

#include <list>
#include "Mac.h"
#include "Wire.h"

class MacTableLine {
 public:
  MacTableLine();
  MacTableLine(Mac, Wire);
  virtual ~MacTableLine();
  Mac getMac();
  void setMac(Mac);
  Wire getWire();
  void setWire(Wire);

 private:
  Mac mac;
  Wire wire;

};

class MacTable {
 public:
  MacTable();
  virtual ~MacTable();
  std::list<MacTableLine> getAllLines();
  MacTableLine getLineByMac(Mac);
  void addLine(MacTableLine);

  void sendFrame(Frame*);

 private:
  std::list<MacTableLine> macTable;

};

#endif
