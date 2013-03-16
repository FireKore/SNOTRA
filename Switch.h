#ifndef __SWITCH_H__
#define __SWITCH_H__

#include <memory>
#include "enum.h"
#include "Frame.h"
#include "MacTable.h"
#include "Mac.h"
#include "Device.h"
#include "DataLinkHeader.h"


class Switch : public Device {
 public:
  Switch();
  virtual ~Switch();
  MacTable getMacTable();
  void setMacTable(MacTable);
  void addNeighbourgToMacTable(Mac, std::shared_ptr<Device>);
  void receiveFrame(std::shared_ptr<Frame>);
  void sendFrame(std::shared_ptr<Frame>);
  void connectNeighbourg(std::shared_ptr<Device>);
  void disconnectNeighbourg(std::shared_ptr<Device>);

 private:
  MacTable macTable;

};

#endif
