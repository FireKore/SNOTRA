#include "TCPHeader.h"

TCPHeader::TCPHeader() {
}

TCPHeader::TCPHeader(int sourcePort, int destinationPort, int frameNumber_, int lastFrameNumber_, unsigned char flags_, bool isAnswer) : UDPHeader(sourcePort, destinationPort, isAnswer) {
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

void TCPHeader::changeFlag(std::string str, bool way) {
  if(str.compare("FIN")) {
    if(way) {
      addFlag(0);
    }
    else {
      removeFlag(0);
    }
  }
  else if(str.compare("SYN")) {
    if(way) {
      addFlag(1);
    }
    else {
      removeFlag(1);
    }
  }
  else if(str.compare("RST")) {
    if(way) {
      addFlag(2);
    }
    else {
      removeFlag(2);
    }
  }
  else if(str.compare("PSH")) {
    if(way) {
      addFlag(3);
    }
    else {
      removeFlag(4);
    }
  }
  else if(str.compare("ACK")) { 
    if(way) {
      addFlag(5);
    }
    else {
      removeFlag(5);
    }   
  }
  else if(str.compare("URG")) {
    if(way) {
      addFlag(6);
    }
    else {
      removeFlag(6);
    }
  }
  else if(str.compare("ECN")) {
    if(way) {
      addFlag(7);
    }
    else {
      removeFlag(7);
    }
  }
  else {
    if(way) {
      addFlag(8);
    }
    else {
      removeFlag(8);
    }
  }
}

void TCPHeader::addFlag(int i) {
  flags = flags | (1u << i);
}

void TCPHeader::removeFlag(int i) {
  flags = flags & !(1u << i);
}
