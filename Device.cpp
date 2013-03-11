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

std::list<Frame*> Device::getFrameHistoryByDestIp(Ip* ip) {
  std::list<Frame*> result;
  return result;
}

std::list<Frame*> Device::getFrameHistoryBySourceIp(Ip* ip) {
  std::list<Frame*> result;
  return result;
}

std::list<Frame*> Device::getFrameHistoryBySourceMac(Mac mac) {
  std::list<Frame*> result;
  return result;
}

std::list<Frame*> Device::getFrameHistoryByDestMac(Mac mac) {
  std::list<Frame*> result;
  return result;
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

