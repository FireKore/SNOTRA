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
  Device::receiveFrame(frame);
  std::shared_ptr<DataLinkHeader> header = std::dynamic_pointer_cast<DataLinkHeader>(frame->getHeader());
  if(macTable.getLineByDevice(frame->getSourceDevice()).getMac() == Mac("00:00:00:00:00:00")) {
    macTable.getLineByDevice(frame->getSourceDevice()).setMac(header->getSource());
  }
  else {
    //TODO : use the renew function on the line in the mac table
  }
  sendFrame(frame);
}

void Switch::sendFrame(std::shared_ptr<Frame> frame) {
  std::shared_ptr<Device> sourceDevice = frame->getSourceDevice();
  frame->setSourceDevice(static_cast<std::shared_ptr<Device>>(this));
  if(frame->getHeader()->getType() == DATALINK) {
    std::shared_ptr<DataLinkHeader> header = std::dynamic_pointer_cast<DataLinkHeader>(frame->getHeader());
    if((header->getDestination() == Mac("FF:FF:FF:FF:FF:FF")) || (!macTable.containsMac(header->getDestination()))) {
      macTable.sendFrameToAllNeighbourgs(frame, sourceDevice);
    }
    else
      macTable.getLineByMac(header->getDestination()).getNeighbourg()->receiveFrame(frame);
  }
}

void Switch::connectNeighbourg(std::shared_ptr<Device> newNeighbourg) {
  addNeighbourgToMacTable(Mac("00:00:00:00:00:00"), newNeighbourg);
}

void Switch::disconnectNeighbourg(std::shared_ptr<Device> device) {
  macTable.removeLineByDevice(device);
}
