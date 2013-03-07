#include "RoutingTable.h"

RoutingTableLine::RoutingTableLine() {
}

RoutingTableLine::~RoutingTableLine() {
}

RoutingTableLine::RoutingTableLine(Ip* dest_, Ip* gateway_, Mask mask_) {
  dest = dest_;
  gateway = gateway_;
  mask = mask_;
}

Ip* RoutingTableLine::getDestIp() {
  return dest;
}

void RoutingTableLine::setDestIp(Ip* ip) {
  dest = ip;
}

Ip* RoutingTableLine::getGateway() {
  return gateway;
}

void RoutingTableLine::setGateway(Ip * gateway_) {
  gateway = gateway_;
}

Mask RoutingTableLine::getMask() {
  return mask;
}

void RoutingTableLine::setMask(Mask mask_) {
  mask = mask_;
}




RoutingTable::RoutingTable() {
}

RoutingTable::~RoutingTable() {
}

std::list<RoutingTableLine> RoutingTable::getAllLines() {
  return routingTable;
}

RoutingTableLine RoutingTable::getLineByIp(Ip* ip) {
  for(std::list<RoutingTableLine>::iterator it = routingTable.begin(); it != routingTable.end(); it++) {
    if(it->getDestIp() == ip) {
      return *it;
    }
  }
  RoutingTableLine line;
  return line;
}

void RoutingTable::addLine(RoutingTableLine line) {
  routingTable.push_back(line);
}
