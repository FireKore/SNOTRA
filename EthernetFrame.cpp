#include "EthernetFrame.h"

EthernetFrame::EthernetFrame() {
}

EthernetFrame::~EthernetFrame() {
}


Protocole EthernetFrame::getProtocole() {
  return data.getProtocole();
}

Ip* EthernetFrame::getSourceIp() {
  return data.getSourceIp();
}

Ip* EthernetFrame::getDestIp() {
  return data.getDestIp();
}


Mac EthernetFrame::getSourceMac() {
  return sourceMac;
}

void EthernetFrame::setSourceMac(Mac mac) {
  sourceMac = mac;
}

Mac EthernetFrame::getDestMac() {
  return destMac;
}

void EthernetFrame::setDestMac(Mac mac) {
  destMac = mac;
}

FrameType EthernetFrame::getFrameType() {
  return frameType;
}

void EthernetFrame::setFrameType(FrameType b) {
  frameType = b;
}

NetworkFrame EthernetFrame::getData() {
  return data;
}

void EthernetFrame::setData(NetworkFrame data_) {
  data = data_;
}
