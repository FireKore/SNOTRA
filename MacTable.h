#ifndef __MACTABLE_H__
#define __MACTABLE_H__

#include <list>
#include <memory>
#include "Mac.h"
#include "Device.h"

class MacTableLine {
 public:
  MacTableLine();
  MacTableLine(Mac, std::shared_ptr<Device>);
  virtual ~MacTableLine();
  Mac getMac();
  void setMac(Mac);
  std::shared_ptr<Device> getNeighbourg();
  void setNeighbourg(std::shared_ptr<Device>);

 private:
  Mac mac;
  std::shared_ptr<Device> neighbourg;

};

class MacTable {
 public:
  MacTable();
  virtual ~MacTable();
  std::list<MacTableLine> getAllLines();
  MacTableLine getLineByMac(Mac);
  void addLine(MacTableLine);


 private:
  std::list<MacTableLine> macTable;

};

#endif
