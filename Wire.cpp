#include "Wire.h"
#include "Device.h"

Wire::Wire() {
}

Wire::Wire(Device* head_, Device* tail_) {
  head = head_;
  tail = tail_;
}

Wire::~Wire() {
}

Device* Wire::getHead() {
  return head;
}

void Wire::setHead(Device* device) {
  head = device;
}

Device* Wire::getTail() {
  return tail;
}

void Wire::setTail(Device* device) {
  tail = device;
}

void Wire::sendFrame(Frame* frame) {
  tail->receiveFrame(frame);
}
