#include "TransportFrame.h"

TransportFrame::TransportFrame() {
}

TransportFrame::~TransportFrame() {
}


FrameType TransportFrame::getFrameType() {
  return NOTHING;
}

Protocole TransportFrame::getProtocole() {
  return NOT;
}

Ip* TransportFrame::getSourceIp() {
  Ip* ip = NULL;
  return ip;
}

Ip* TransportFrame::getDestIp() {
  Ip* ip = NULL;
  return ip;
}

Mac TransportFrame::getSourceMac() {
  Mac mac;
  return mac;
}

Mac TransportFrame::getDestMac() {
  Mac mac;
  return mac;
}
