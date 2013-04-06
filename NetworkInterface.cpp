#include "NetworkInterface.h"

NetworkInterface::NetworkInterface() {
}

NetworkInterface::NetworkInterface(std::string name_, Mac mac_, std::shared_ptr<Ip> ip_, bool isUp_) {
  ip = ip_;
  mac = mac_;
  isUp = isUp_;
  name = name_;
}

NetworkInterface::~NetworkInterface() {
}

Mac NetworkInterface::getMac() const {
  return mac;
}

void NetworkInterface::setMac(Mac mac_) {
  mac = mac_;
}

std::shared_ptr<Ip> NetworkInterface::getIp() const {
  return ip;
}

void NetworkInterface::setIp(std::shared_ptr<Ip> ip_) {
  ip = ip_;
}

bool NetworkInterface::getIsUp() const {
  return isUp;
}

void NetworkInterface::setIsUp(bool isUp_) {
  isUp = isUp_;
}

std::string NetworkInterface::getName() const {
  return name;
}

void NetworkInterface::setName(std::string name_) {
  name = name_;
}

std::vector<Wire> NetworkInterface::getWire() const {
  return wires;
}

void NetworkInterface::connectWire(Wire wire_) {
  wires.push_back(wire_);
}

void NetworkInterface::disconnectWire(int wireId) {
  wires.erase(wires.begin() + wireId);
}

std::shared_ptr<Frame> NetworkInterface::receiveFrame(std::shared_ptr<Frame> frame) {
  std::shared_ptr<Frame> newFrame = (std::shared_ptr<Frame>)0;
  std::shared_ptr<DataLinkHeader> header = std::dynamic_pointer_cast<DataLinkHeader>(frame->getHeader());
  if((header->getDestination() == mac) || (header->getDestination() == Mac("FF:FF:FF:FF:FF:FF"))) {
    newFrame = frame->getData();
  }
  return newFrame;
}

void NetworkInterface::sendFrame(std::shared_ptr<Frame> frame, int portId) {
  if(isUp) {
    wires.at(portId).sendFrame(frame);
  }
}

void NetworkInterface::createFrame(std::shared_ptr<Frame> frame, Mac destinationMac, int portId) {
  std::static_pointer_cast<NetworkHeader>(frame->getHeader())->setSource(ip);
  std::shared_ptr<Header> header (new DataLinkHeader(mac, destinationMac, false));
  std::shared_ptr<Frame> newFrame (new Frame(frame, header, 0, 0));
  sendFrame(newFrame, portId);
}

int NetworkInterface::getNumberOfWires() const {
  return wires.size();
}
