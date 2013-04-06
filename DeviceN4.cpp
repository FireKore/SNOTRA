#include "DeviceN4.h"

DeviceN4::DeviceN4() {
}

DeviceN4::~DeviceN4() {
}

RoutingTable DeviceN4::getRoutingTable() const {
  return routingTable;
}

void DeviceN4::setRoutingTable(RoutingTable routingTable_) {
  routingTable = routingTable_;
}

ARPTable DeviceN4::getARPTable() const {
  return arpTable;
}

void DeviceN4::setARPTable(ARPTable arpTable_) {
  arpTable = arpTable_;
}


void DeviceN4::receiveFrame(std::shared_ptr<Frame> frame, int interfaceId, int portId) {
  Device::receiveFrame(frame, interfaceId, portId);
  std::shared_ptr<Frame> newFrame = Device::giveFrameToInterface(frame, interfaceId);
  if (newFrame != (std::shared_ptr<Frame>)0) {
    std::shared_ptr<NetworkHeader> newHeader = std::dynamic_pointer_cast<NetworkHeader>(newFrame->getHeader());
    newHeader->decreaseTimeToLive();
    //TODO : tester si l'IP est acceptable
    //if((newHeader->getDestination() == getNetworkInterfaces().at(interfaceId).getIp)) {
    //TODO : use the frame depending on the protocole
    //}
  }
}

void DeviceN4::sendFrame(std::shared_ptr<Frame> frame) {
  std::shared_ptr<DataLinkHeader> header = std::dynamic_pointer_cast<DataLinkHeader>(frame->getHeader());
  if (header->getDestination() == Mac("FF:FF:FF:FF:FF:FF")) {
    Device::sendFrameBroadcast(frame);
  }
  else {
    Device::sendFrameUnicast(frame, frame->getInterfaceId(), frame->getPortId());
  }
}

void DeviceN4::createFrame(std::shared_ptr<Ip> destination, std::string protocole) {
  std::shared_ptr<Frame> frame;
  int temp = routingTable.getLineByIp(destination).second;
  if(temp != -1) {
    std::shared_ptr<Ip> source = getNetworkInterfaces().at(temp).getIp();
    std::shared_ptr<Ip> gateway = routingTable.getLineByIp(destination).first;
    if(protocole.compare("ARP")) {
      std::shared_ptr<Header> networkHeader = std::shared_ptr<ARPHeader>(new ARPHeader(source, destination, STANDART_TTL, NONE, getNetworkInterfaces().at(temp).getMac(), Mac("FF:FF:FF:FF:FF:FF"), false));
      frame = std::shared_ptr<Frame>(new Frame(0, networkHeader, 0, 0));
    } else if(protocole.compare("UDP")) {
      //TODO
    } else if(protocole.compare("TCP")) {
      //TODO
    } else if(protocole.compare("ICMP")) {
      std::shared_ptr<Header> transportHeader = std::shared_ptr<ICMPHeader>(new ICMPHeader(source, false));
      std::shared_ptr<Frame> transportFrame = std::shared_ptr<Frame>(new Frame(0, transportHeader, 0, 0));
      std::shared_ptr<Header> networkHeader = std::shared_ptr<Header>(new NetworkHeader(source, destination, STANDART_TTL, NONE, false));
      frame = std::shared_ptr<Frame>(new Frame(transportFrame, networkHeader, 0, 0));
    }
  }
  getNetworkInterfaces().at(temp).sendFrame(frame, 0);
}
