#include "RoutingTable.h"

//RoutingTableLine 

RoutingTableLine::RoutingTableLine() {
}

RoutingTableLine::~RoutingTableLine() {
}

RoutingTableLine::RoutingTableLine(std::shared_ptr<Ip> dest_, std::shared_ptr<Ip> gateway_, Mask mask_, NetworkInterface interface_) {
  dest = dest_;
  gateway = gateway_;
  mask = mask_;
  interface = interface_;
}

std::shared_ptr<Ip> RoutingTableLine::getDestIp() {
  return dest;
}

void RoutingTableLine::setDestIp(std::shared_ptr<Ip> ip) {
  dest = ip;
}

std::shared_ptr<Ip> RoutingTableLine::getGateway() {
  return gateway;
}

void RoutingTableLine::setGateway(std::shared_ptr<Ip> gateway_) {
  gateway = gateway_;
}

Mask RoutingTableLine::getMask() {
  return mask;
}

void RoutingTableLine::setMask(Mask mask_) {
  mask = mask_;
}

NetworkInterface RoutingTableLine::getNetworkInterface() {
  return interface;
}

void RoutingTableLine::setNetworkInterface(NetworkInterface interface_) {
  interface = interface_;
}



//RoutingTable

RoutingTable::RoutingTable() {
}

RoutingTable::~RoutingTable() {
}

std::list<RoutingTableLine> RoutingTable::getAllLines() {
  return routingTable;
}

RoutingTableLine RoutingTable::getLineByIp(std::shared_ptr<Ip> ip) {
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
