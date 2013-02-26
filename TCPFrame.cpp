#include "TCPFrame.h"

TCPFrame::TCPFrame() {
}

TCPFrame::~TCPFrame() {
}

int TCPFrame::getSeqNumber() {
  return seqNumber;
}

void TCPFrame::setSeqNumber(int number) {
  seqNumber = number;
}

int TCPFrame::getAckNumber() {
  return ackNumber;
}

void TCPFrame::setAckNumber(int number) {
  ackNumber = number;
}

std::list<Flag> TCPFrame::getAllFlags() {
  return flags;
}

void TCPFrame::addFlag(Flag flag) {
  flags.push_back(flag);
}

bool TCPFrame::isAck() {
  for(std::list<Flag>::iterator it = flags.begin(); it != flags.end(); it++) {
    if(*it == ACK)
      return true;
  }
  return false;
}

bool TCPFrame::isSyn() {
  for(std::list<Flag>::iterator it = flags.begin(); it != flags.end(); it++) {
    if(*it == SYN)
      return true;
  }
  return false;
}

bool TCPFrame::isFin() {
  for(std::list<Flag>::iterator it = flags.begin(); it != flags.end(); it++) {
    if(*it == FIN)
      return true;
  }
  return false;
}
