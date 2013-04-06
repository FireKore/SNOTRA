#include "RoutingTable.h"

RoutingTable::RoutingTable() {
}

RoutingTable::~RoutingTable() {
}

std::map<std::shared_ptr<Ip>, std::pair<std::shared_ptr<Ip>, int>> RoutingTable::getAllLines() {
  return routingTable;
}

void RoutingTable::resetRoutingTable() {
  routingTable.clear();
}

std::pair<std::shared_ptr<Ip>, int> RoutingTable::getLineByIp(std::shared_ptr<Ip> ip) {
  for(auto& it : routingTable) {
    if(it.first->getNetwork() == ip->getNetwork()) {
      return it.second;
    }
  }
  return std::pair<std::shared_ptr<Ip>, int>((std::shared_ptr<Ip>)0, -1);
}

void RoutingTable::addLine(std::shared_ptr<Ip> destination, std::shared_ptr<Ip> gateway, int interfaceId) {
  routingTable.insert(std::pair<std::shared_ptr<Ip>, std::pair<std::shared_ptr<Ip>, int>>(destination, std::pair<std::shared_ptr<Ip>, int>(gateway, interfaceId)));
}

void RoutingTable::removeLine(std::shared_ptr<Ip> destination) {
  routingTable.erase(destination);
}
