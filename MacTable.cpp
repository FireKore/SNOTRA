#include "MacTable.h"

//MacTable

MacTable::MacTable() {
}

MacTable::~MacTable() {
}

std::list<MacTableLine> MacTable::getAllLines() {
  return macTable;
}

MacTableLine MacTable::getLineByMac(Mac mac) {
  for(std::list<MacTableLine>::iterator it = macTable.begin(); it != macTable.end(); it++) {
    if(it->getMac() == mac) {
      return *it;
    }
  }
  MacTableLine line;
  return line;
}

void MacTable::addLine(MacTableLine line) {
  macTable.push_back(line);
}



//MacTableLine

MacTableLine::MacTableLine() {
}

MacTableLine::MacTableLine(Mac mac_, std::shared_ptr<Device> device) {
  mac = mac_;
  neighbourg = device;
}

MacTableLine::~MacTableLine() {
}

Mac MacTableLine::getMac() {
  return mac;
}

void MacTableLine::setMac(Mac mac_) {
  mac = mac_;
}

std::shared_ptr<Device> MacTableLine::getNeighbourg() {
  return neighbourg;
}

void MacTableLine::setNeighbourg(std::shared_ptr<Device> device) {
  neighbourg = device;
}
