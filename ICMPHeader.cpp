#include "ICMPHeader.h"

ICMPHeader::ICMPHeader() {
}

ICMPHeader::ICMPHeader(std::shared_ptr<Ip> ip, bool isAnswer) : TransportHeader(isAnswer) {
  sourceIp = ip;
}

ICMPHeader::~ICMPHeader() {
}

std::shared_ptr<Ip> ICMPHeader::getSourceIp() {
  return sourceIp;
}

void ICMPHeader::setSourceIp(std::shared_ptr<Ip> ip) {
  sourceIp = ip;
}
