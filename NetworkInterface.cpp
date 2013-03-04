#include "NetworkInterface.h"

NetworkInterface::NetworkInterface() {
}

NetworkInterface::NetworkInterface(Mac mac_, Ip* ip_) {
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

Ip* NetworkInterface::getIp() {
  return ip;
}

void NetworkInterface::setIp(Ip* ip_) {
  ip = ip_;
}

MacTable NetworkInterface::getMacTable() {
  return macTable;
}

void NetworkInterface::setMacTable(MacTable table) {
  macTable = table;
}


Frame* NetworkInterface::createEthernetFrame(Frame* data, Mac dest, FrameType type) {
  Frame* frame = new EthernetFrame(mac, dest, type, data);
  return frame;
}

void NetworkInterface::sendFrame(Frame* frame) {
  macTable.sendFrame(frame);
}
