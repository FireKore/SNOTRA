#include "NetworkInterface.h"

NetworkInterface::NetworkInterface() {
}

NetworkInterface::NetworkInterface(Mac mac_, std::shared_ptr<Ip> ip_) {
  ip = ip_;
  mac = mac_;
}

NetworkInterface::~NetworkInterface() {
}

Mac NetworkInterface::getMac() {
  return mac;
}

void NetworkInterface::setMac(Mac mac_) {
  mac = mac_;
}

std::shared_ptr<Ip> NetworkInterface::getIp() {
  return ip;
}

void NetworkInterface::setIp(std::shared_ptr<Ip> ip_) {
  ip = ip_;
}

std::shared_ptr<Frame> NetworkInterface::receiveFrame(std::shared_ptr<Frame> frame) {
  std::shared_ptr<DataLinkHeader> header = std::dynamic_pointer_cast<DataLinkHeader>(frame->getHeader());
  if((header->getDestination() == mac) || (header->getDestination() == Mac("FF:FF:FF:FF:FF:FF"))) {
    std::shared_ptr<Frame> newFrame = frame->getData();
    std::shared_ptr<NetworkHeader> newHeader = std::dynamic_pointer_cast<NetworkHeader>(newFrame->getHeader());
    if((newHeader->getDestination() == ip)/* || (newHeader->getDestination() == //Insérer ici Ip de broadcast)*/) {
      return newFrame;
    }
  }
  return (std::shared_ptr<Frame>)0;
}

std::shared_ptr<Frame> NetworkInterface::createFrame(std::shared_ptr<Frame> frame) {
  std::static_pointer_cast<NetworkHeader>(frame->getHeader())->setSource(ip);
  std::shared_ptr<Header> header (new DataLinkHeader(mac, Mac("00:00:00:00:00:00"), false));
  std::shared_ptr<Frame> newFrame (new Frame(frame, header, 0));
  return newFrame;
}
