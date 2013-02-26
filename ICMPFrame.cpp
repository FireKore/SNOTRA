#include "ICMPFrame.h"

ICMPFrame::ICMPFrame() {
}

ICMPFrame::~ICMPFrame() {
}

Ip* ICMPFrame::getSourceIp() {
  return sourceIp;
}

void ICMPFrame::setSourceIp(Ip* ip) {
  sourceIp = ip;
}

bool ICMPFrame::getIsRequest() {
  return isRequest;
}

void ICMPFrame::setIsRequest(bool b) {
  isRequest = b;
}
