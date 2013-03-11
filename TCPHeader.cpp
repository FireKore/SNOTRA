#include "TCPHeader.h"

TCPHeader::TCPHeader() {
}

TCPHeader::TCPHeader(int sourcePort, int destinationPort, int frameNumber_, int lastFrameNumber_, unsigned char flags_) : UDPHeader(sourcePort, destinationPort) {
  frameNumber = frameNumber_;
  lastFrameNumber = lastFrameNumber_;
  flags = flags_;
}

TCPHeader::~TCPHeader() {
}

int TCPHeader::getFrameNumber() {
  return frameNumber;
}

void TCPHeader::setFrameNumber(int frameNumber_) {
  frameNumber = frameNumber_;
}

int TCPHeader::getLastFrameNumber() {
  return lastFrameNumber;
}

void TCPHeader::setLastFrameNumber(int lastFrameNumber_) {
  lastFrameNumber = lastFrameNumber_;
}

unsigned char TCPHeader::getFlags() {
  return flags;
}

void TCPHeader::setFlags(unsigned char flags_) {
  flags = flags_;
}

void TCPHeader::addFlag(std::string str) {
  //TODO
}
