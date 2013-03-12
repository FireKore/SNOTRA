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
  for(std::list<std::shared_ptr<Device>>::iterator it = neighbours.begin(); it != neighbours.end(); it++) {
    (*it)->receiveFrame(frame);
  }
}
