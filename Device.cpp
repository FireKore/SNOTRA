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

std::list<NetworkInterface> Device::getAllNetworkInterface() {
  return networkInterfaces;
}

void Device::addNetworkInterface(NetworkInterface interface) {
  networkInterfaces.push_back(interface);
}

NetworkInterface Device::getNetworkInterfaceByMac(Mac mac) {
  for(std::list<NetworkInterface>::iterator it = networkInterfaces.begin(); it != networkInterfaces.end(); it++) {
    if(it->getMac() == mac) {
      return *it;
    }
  }
  NetworkInterface net;
  return net;
}


void Device::receiveFrame(Frame* frame) {
  addFrameToHistory(frame);
  //TODO
}

Frame* Device::createFrame(Ip*) {
  Frame* frame;
  //TODO
  return frame;
}

void Device::sendFrame(Frame* frame) {
  getNetworkInterfaceByMac(frame->getSourceMac()).sendFrame(frame);
}
