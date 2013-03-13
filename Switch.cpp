#include "Switch.h"

Switch::Switch() {
}

Switch::~Switch() {
}

MacTable Switch::getMacTable() {
  return macTable;
}

void Switch::setMacTable(MacTable macTable_) {
  macTable = macTable_;
}

void Switch::addNeighbourgToMacTable(Mac mac_, std::shared_ptr<Device> device) {
  macTable.addLine(MacTableLine(mac_, device));
}

void Switch::receiveFrame(std::shared_ptr<Frame> frame) {
  sendFrame(frame);
}

void Switch::sendFrame(std::shared_ptr<Frame> frame) {
  if(frame->getHeader().getType() == DATALINK) {
    macTable.getLineByMac((DataLinkHeader)(frame->getHeader()).getDestinationMac()).getNeighbourg()->receive(frame);
  }
}
