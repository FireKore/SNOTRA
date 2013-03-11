#include "ARPTable.h"

ARPTableLine::ARPTableLine() {
}

ARPTableLine::ARPTableLine(Ip* ip_, Mac mac_) {
  ip = ip_;
  mac = mac_;
}

ARPTableLine::~ARPTableLine() {
}

Ip* ARPTableLine::getIp() {
  return ip;
}

void ARPTableLine::setIp(Ip* ip_) {
  ip = ip_;
}

Mac ARPTableLine::getMac() {
  return mac;
}

void ARPTableLine::setMac(Mac mac_) {
  mac = mac_;
}






ARPTable::ARPTable() {
}

ARPTable::~ARPTable() {
}

std::list<ARPTableLine> ARPTable::getAllLines() {
  return arpTable;
}

ARPTableLine ARPTable::getLineByIp(Ip* ip) {
  for(std::list<ARPTableLine>::iterator it = arpTable.begin(); it != arpTable.end(); it++) {
    if(it->getIp() == ip) {
      return *it;
    }
  }
  ARPTableLine line;
  return line;
}

void ARPTable::addLine(ARPTableLine line) {
  arpTable.push_back(line);
}
