#include "EthernetFrame.h"

Mac EthernetFrame::getMacSource() {
  return macSource;
}

void EthernetFrame::setMacSource(Mac mac) {
  macSource = mac;
}

Mac EthernetFrame::getMacDest() {
  return macDest;
}

void EthernetFrame::setMacDest(Mac mac) {
  macDest = mac;
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
