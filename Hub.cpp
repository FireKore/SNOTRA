#include "Hub.h"

Hub::Hub() {
}

Hub::~Hub() {
}

void Hub::receiveFrame(std::shared_ptr<Frame> frame, int interfaceId) {
  Device::receiveFrame(frame, interfaceId);
  sendFrame(frame);
}

void Hub::sendFrame(std::shared_ptr<Frame> frame) {
  Device::sendFrameBroadcast(frame, frame->getInterfaceId());
}
