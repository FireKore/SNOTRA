#include "NetworkInterface.h"

NetworkInterface::NetworkInterface() {
}

NetworkInterface::NetworkInterface(Mac mac_, std::shared_ptr<Ip> ip_, std::shared_ptr<Device> neighbourg_) {
  ip = ip_;
  mac = mac_;
  neighbourg = neighbourg_;
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

std::shared_ptr<Device> NetworkInterface::getNeighbourg() {
  return neighbourg;
}

void NetworkInterface::setNeighbourg(std::shared_ptr<Device> neighbourg_) {
  neighbourg = neighbourg_;
}

