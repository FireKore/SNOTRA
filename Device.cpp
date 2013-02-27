#include "Device.h"

Device::Device() {
}

Device::~Device() {
}

std::list<Frame*> Device::getAllFrameHistory() {
  return frameHistory;
}

void Device::addFrameToHistory(Frame* frame) {
  frameHistory.push_back(frame);
}

std::list<Frame*> Device::getFrameHistoryByType(FrameType type) {
  std::list<Frame*> result;
  for(std::list<Frame*>::iterator it = frameHistory.begin(); it != frameHistory.end(); it++) {
    if((*it)->getFrameType() == type) {
      result.push_back(*it);
    }
  }
  return result;
}


std::list<Frame*> Device::getFrameHistoryByProtocole(Protocole protocole) {
  std::list<Frame*> result;
  for(std::list<Frame*>::iterator it = frameHistory.begin(); it != frameHistory.end(); it++) {
    if((*it)->getProtocole() == protocole) {
      result.push_back(*it);
    }
  }
  return result;
}

std::list<Frame*> Device::getFrameHistoryByDestIp(Ip* ip) {
  std::list<Frame*> result;
  for(std::list<Frame*>::iterator it = frameHistory.begin(); it != frameHistory.end(); it++) {
    if((*it)->getDestIp() == ip) {
      result.push_back(*it);
    }
  }
  return result;
}

std::list<Frame*> Device::getFrameHistoryBySourceIp(Ip* ip) {
  std::list<Frame*> result;
  for(std::list<Frame*>::iterator it = frameHistory.begin(); it != frameHistory.end(); it++) {
    if((*it)->getDestIp() == ip) {
      result.push_back(*it);
    }
  }
  return result;
}

std::list<Frame*> Device::getFrameHistoryBySourceMac(Mac mac) {
  std::list<Frame*> result;
  for(std::list<Frame*>::iterator it = frameHistory.begin(); it != frameHistory.end(); it++) {
    if((*it)->getSourceMac() == mac) {
      result.push_back(*it);
    }
  }
  return result;
}

std::list<Frame*> Device::getFrameHistoryByDestMac(Mac mac) {
  std::list<Frame*> result;
  for(std::list<Frame*>::iterator it = frameHistory.begin(); it != frameHistory.end(); it++) {
    if((*it)->getDestMac() == mac) {
      result.push_back(*it);
    }
  }
  return result;
}


