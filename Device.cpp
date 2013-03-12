#include "Device.h"

Device::Device() {
}

Device::~Device() {
}

std::list<std::shared_ptr<Frame>> Device::getAllFrameHistory() {
  return frameHistory;
}

void Device::addFrameToHistory(std::shared_ptr<Frame> frame) {
  frameHistory.push_back(frame);
}

void Device::receiveFrame(std::shared_ptr<Frame> frame) {
  addFrameToHistory(frame);
}
