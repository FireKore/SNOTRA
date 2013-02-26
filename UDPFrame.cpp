#include "UDPFrame.h"

UDPFrame::UDPFrame() {
}

UDPFrame::~UDPFrame() {
}

int UDPFrame::getSourcePort() {
  return sourcePort;
}

void UDPFrame::setSourcePort(int port) {
  sourcePort = port;
}

int UDPFrame::getDestPort() {
  return destPort;
}

void UDPFrame::setDestPort(int port) {
  destPort = port;
}
