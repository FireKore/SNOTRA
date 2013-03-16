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
  //TODO : Add a function to renew the ttl of the line

 private:
  Mac mac;
  std::shared_ptr<Device> neighbourg;
  //TODO : Add the time to live of the line

};

class MacTable {
 public:
  MacTable();
  virtual ~MacTable();
  std::list<MacTableLine> getAllLines();
  MacTableLine getLineByMac(Mac);
  MacTableLine getLineByDevice(std::shared_ptr<Device>);
  void addLine(MacTableLine);
  void removeLineByDevice(std::shared_ptr<Device>);
  void resetMacTable();
  bool containsMac(Mac);


 private:
  std::list<MacTableLine> macTable;

};

#endif
