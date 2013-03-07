#ifndef __ROUTINGTABLE_H__
#define __ROUTINGTABLE_H__

#include <list>
#include "Ip.h"
#include "Mask.h"

// attention: plantage encas de copie d'une ligne

class RoutingTableLine {
 public:
  RoutingTableLine();
  RoutingTableLine(Ip*, Ip*, Mask);
  virtual ~RoutingTableLine();
  Ip* getDestIp();
  void setDestIp(Ip*);
  Ip* getGateway();
  void setGateway(Ip*);
  Mask getMask();
  void setMask(Mask);

 private:
  Ip* dest;
  Ip* gateway;
  Mask mask;

};

class RoutingTable {
 public:
  RoutingTable();
  virtual ~RoutingTable();
  std::list<RoutingTableLine> getAllLines();
  RoutingTableLine getLineByIp(Ip*);
  // hop plantage
  void addLine(RoutingTableLine);

 private:
  std::list<RoutingTableLine> routingTable;

};

#endif
