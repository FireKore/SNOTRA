#ifndef __ROUTINGTABLE_H__
#define __ROUTINGTABLE_H__

#include <map>
#include <memory>
#include "Ip.h"
#include "NetworkInterface.h"

class RoutingTable {
 public:
  RoutingTable();
  virtual ~RoutingTable();
  std::map<std::shared_ptr<Ip>, std::pair<std::shared_ptr<Ip>, int>> getAllLines();
  void resetRoutingTable();
  std::pair<std::shared_ptr<Ip>, int> getLineByIp(std::shared_ptr<Ip>);
  void addLine(std::shared_ptr<Ip>, std::shared_ptr<Ip>, int);
  void removeLine(std::shared_ptr<Ip>);

 private:
  std::map<std::shared_ptr<Ip>, std::pair<std::shared_ptr<Ip>, int>> routingTable;

};

#endif
