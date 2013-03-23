#include "ICMPHeader.h"

ICMPHeader::ICMPHeader() {
}

ICMPHeader::ICMPHeader(std::shared_ptr<Ip> ip, bool isAnswer) : TransportHeader(isAnswer) {
  sourceIp = ip;
  creationTime = time(&creationTime);
}

ICMPHeader::~ICMPHeader() {
}

time_t ICMPHeader::getTime() {
  return creationTime;
}

void ICMPHeader::setTime(time_t time) {
  creationTime = time;
}

void ICMPHeader::setTimeNow() {
  creationTime = time(&creationTime);
}

std::shared_ptr<Ip> ICMPHeader::getSourceIp() {
  return sourceIp;
}

void ICMPHeader::setSourceIp(std::shared_ptr<Ip> ip) {
  sourceIp = ip;
}
