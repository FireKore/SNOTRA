#include "ICMPHeader.h"

ICMPHeader::ICMPHeader() {
}

ICMPHeader::ICMPHeader(Ip ip, bool isAnswer_){
  sourceIp = ip;
  isAnswer = isAnswer_;
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

Ip ICMPHeader::getSourceIp() {
  return sourceIp;
}

void ICMPHeader::setSourceIp(Ip ip) {
  sourceIp = ip;
}

bool ICMPHeader::getIsAnswer() {
  return isAnswer;
}

void ICMPHeader::setIsAnswer(bool isAnswer_) {
  isAnswer = isAnswer_;
}
