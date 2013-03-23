#include "MacTable.h"

MacTable::MacTable() {
}

MacTable::MacTable(int numberOfInterface) {
  for(int i = 1; i <= numberOfInterface; i++) {
    macTable.insert(std::pair<int, std::list<Mac>>(i, std::list<Mac>()));
  }
}

MacTable::~MacTable() {
}

std::map<int, std::list<Mac>> MacTable::getAllLines() {
  return macTable;
}

void MacTable::resetMacTable() {
  for (auto& it : macTable) {
    it.second.clear();
  }
}

int MacTable::containsMac(Mac mac) {
  for (auto& it : macTable) {
    for(auto& i : it.second) {
      if(i == mac) {
	return it.first;
      }
    }
  }
  return 0;
}

void MacTable::saveMac(Mac mac, int interfaceId) {
  int temp = containsMac(mac);
  if(temp == 0) {
    addMac(mac, interfaceId);
  }
  else {
    //TODO : use the renew method once created on the mac in the interface
  }
}

void MacTable::checkForDeletion() {
  for(auto& it : macTable) {
    for(auto& i : it.second) {
      //TODO : test the ttl and delete the Mac if it expired
    }
  }
}

void MacTable::addMac(Mac mac, int interfaceId) {
  macTable.at(interfaceId).push_back(mac);
}

void MacTable::removeMac(Mac mac, int interfaceId) {
  macTable.at(interfaceId).remove(mac);
}
