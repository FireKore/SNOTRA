#include "Device.h"

Device::Device() {
}

Device::~Device() {
}

std::list<std::shared_ptr<Frame>> Device::getAllFrameHistory() const{
  return frameHistory;
}

Wire Device::getWireByNetworkInterfaceID(int id) const{
  return wires.at(id);
}

void Device::addFrameToHistory(std::shared_ptr<Frame> frame) {
  frameHistory.push_back(frame);
}

void Device::sendFrameBroadcast(std::shared_ptr<Frame> frame, int interfaceId) {
  for(auto& it : wires) {
    if(it.first != interfaceId) {
      sendFrameUnicast(frame, it.first);
    }
  }
}

void Device::sendFrameUnicast(std::shared_ptr<Frame> frame, int interfaceId) {
  frame->setInterfaceId(interfaceId);
  addFrameToHistory(frame);
  wires.at(interfaceId).sendFrame(frame);
}

void Device::receiveFrame(std::shared_ptr<Frame> frame, int interfaceId) {
  frame->setInterfaceId(interfaceId);
  addFrameToHistory(frame);
}

void Device::connectNeighbour(std::shared_ptr<Device> neighbour, int thisId, int neighbourId) {
  wires.insert(std::pair<int, Wire>(thisId, Wire((std::shared_ptr<Device>)this, thisId, neighbour, neighbourId)));
}
