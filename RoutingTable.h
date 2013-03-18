#ifndef __ROUTINGTABLE_H__
#define __ROUTINGTABLE_H__

#include <memory>
#include <list>
#include "Ip.h"
#include "Mask.h"
#include "NetworkInterface.h"

class RoutingTableLine {
 public:
  RoutingTableLine();
  RoutingTableLine(std::shared_ptr<Ip>, std::shared_ptr<Ip>, Mask, NetworkInterface);
  virtual ~RoutingTableLine();
  std::shared_ptr<Ip> getDestIp();
  void setDestIp(std::shared_ptr<Ip>);
  std::shared_ptr<Ip> getGateway();
  void setGateway(std::shared_ptr<Ip>);
  Mask getMask();
  void setMask(Mask);
  NetworkInterface getNetworkInterface();
  void setNetworkInterface(NetworkInterface);

 private:
  std::shared_ptr<Ip> dest;
  std::shared_ptr<Ip> gateway;
  Mask mask;
  NetworkInterface interface;

};

class RoutingTable {
 public:
  RoutingTable();
  virtual ~RoutingTable();
  std::list<RoutingTableLine> getAllLines();
  RoutingTableLine getLineByIp(std::shared_ptr<Ip>);
  void addLine(RoutingTableLine);

 private:
  std::list<RoutingTableLine> routingTable;

};

#endif
