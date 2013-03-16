#include "Hub.h"

Hub::Hub() {
}

Hub::~Hub() {
}

void Hub::receiveFrame(std::shared_ptr<Frame> frame) {
  Device::receiveFrame(frame);
  sendFrame(frame);
}

void Hub::sendFrame(std::shared_ptr<Frame> frame) {
  std::shared_ptr<Device> sourceDevice = frame->getSourceDevice();
  frame->setSourceDevice(static_cast<std::shared_ptr<Device>>(this));
  for(std::list<std::shared_ptr<Device>>::iterator it = neighbourgs.begin(); it != neighbourgs.end(); it++) {
    if(*it != sourceDevice) {
      (*it)->receiveFrame(frame);
    }
  }
}

std::list<std::shared_ptr<Device>> Hub::getNeighbourgs() {
  return neighbourgs;
}

void Hub::connectNeighbourg(std::shared_ptr<Device> newNeighbourg) {
  neighbourgs.push_back(newNeighbourg);
}

void Hub::disconnectNeighbourg(std::shared_ptr<Device> device) {
  for(std::list<std::shared_ptr<Device>>::iterator it = neighbourgs.begin(); it != neighbourgs.end(); it++) {
    if(*it == device) {
      neighbourgs.erase(it);
    }
  }
}
