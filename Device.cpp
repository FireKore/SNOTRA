#include "Device.h"

Device::Device() {
}

Device::~Device() {
}

std::list<std::shared_ptr<Frame>> Device::getAllFrameHistory() const{
  return frameHistory;
}

std::vector<NetworkInterface> Device::getNetworkInterfaces() const {
  return networkInterfaces;
}

void Device::addFrameToHistory(std::shared_ptr<Frame> frame) {
  frameHistory.push_back(frame);
}

void Device::sendFrameBroadcast(std::shared_ptr<Frame> frame) {
  for(int i = 0; i < networkInterfaces.size(); i++) {
    for(int j = 0; j < networkInterfaces.at(i).getNumberOfWires(); j++) {
      if((i != frame->getInterfaceId()) || (j != frame->getPortId())) {
	sendFrameUnicast(frame, i, j);
      }
    }
  }
}

void Device::sendFrameUnicast(std::shared_ptr<Frame> frame, int interfaceId, int portId) {
  frame->setInterfaceId(interfaceId);
  frame->setPortId(portId);
  addFrameToHistory(frame);
  networkInterfaces.at(interfaceId).sendFrame(frame, portId);
}

void Device::receiveFrame(std::shared_ptr<Frame> frame, int interfaceId, int portId) {
  frame->setInterfaceId(interfaceId);
  frame->setPortId(portId);
  addFrameToHistory(frame);
}

std::shared_ptr<Frame> Device::giveFrameToInterface(std::shared_ptr<Frame> frame, int interfaceId) {
  return networkInterfaces.at(interfaceId).receiveFrame(frame);
}

void Device::addNetworkInterface(std::string name, Mac mac, std::shared_ptr<Ip> ip, bool isUp) {
  networkInterfaces.push_back(NetworkInterface(name, mac, ip, isUp));
}

void Device::connectNeighbour(std::shared_ptr<Device> neighbour, int thisInterfaceId, int thisPortId, int neighbourInterfaceId, int neighbourPortId) {
  networkInterfaces.at(thisInterfaceId).connectWire(Wire((std::shared_ptr<Device>)this, thisInterfaceId, thisPortId, neighbour, neighbourInterfaceId, neighbourPortId));
}

void Device::disconnectNeighbour(int interfaceId) {
  networkInterfaces.erase(networkInterfaces.begin() + interfaceId);
}

void Device::activateNetworkInterface(int interfaceId) {
  networkInterfaces.at(interfaceId).setIsUp(true);
}

void Device::desactivateNetworkInterface(int interfaceId) {
  networkInterfaces.at(interfaceId).setIsUp(false);
}
