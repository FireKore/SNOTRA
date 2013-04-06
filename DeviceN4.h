#ifndef __DEVICEN4_H__
#define __DEVICEN4_H__

#define STANDART_TTL 64

#include <map>
#include <memory>
#include "enum.h"
#include "Device.h"
#include "ARPTable.h"
#include "RoutingTable.h"
#include "NetworkInterface.h"
#include "ARPHeader.h"
#include "ICMPHeader.h"

class DeviceN4 : public Device {
 public:
  DeviceN4();
  virtual ~DeviceN4();
  RoutingTable getRoutingTable() const;
  void setRoutingTable(RoutingTable);
  ARPTable getARPTable() const;
  void setARPTable(ARPTable);
  virtual void receiveFrame(std::shared_ptr<Frame>, int, int);
  virtual void sendFrame(std::shared_ptr<Frame>);
  void createFrame(std::shared_ptr<Ip>, std::string);

 private:
  RoutingTable routingTable;
  ARPTable arpTable;

};

#endif
