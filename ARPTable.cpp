#include "ARPTable.h"

ARPTable::ARPTable() {
}

ARPTable::~ARPTable() {
}

std::map<std::shared_ptr<Ip>, Mac> ARPTable::getAllLines() {
  return arpTable;
}

void ARPTable::resetARPTable() {
  arpTable.clear();
}

Mac ARPTable::getMacByIp(std::shared_ptr<Ip> ip) {
  return arpTable.at(ip);
}

void ARPTable::addLine(std::shared_ptr<Ip> ip, Mac mac) {
  arpTable.insert(std::pair<std::shared_ptr<Ip>, Mac>(ip, mac));
}

void ARPTable::checkForDeletion() {
  for(auto& it : arpTable) {
    //TODO : test the ttl and delete the Mac if it expired
  }
}

void ARPTable::removeLine(std::shared_ptr<Ip> ip) {
  arpTable.erase(ip);
}
