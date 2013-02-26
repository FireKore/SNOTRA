#include "ARPFrame.h"

ARPFrame::ARPFrame() {
}

ARPFrame::~ARPFrame() {
}

Mac ARPFrame::getMacSource() {
  return macSource;
}

void ARPFrame::setMacSource(Mac mac) {
  macSource = mac;
}

Mac ARPFrame::getMacDest() {
  return macDest;
}

void ARPFrame::setMacDest(Mac mac) {
  macDest = mac;
}
