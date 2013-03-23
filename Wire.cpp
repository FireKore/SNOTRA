#include "Wire.h"
#include "Device.h"

Wire::Wire() {
}

Wire::Wire(std::shared_ptr<Device> head_, int headPort_, std::shared_ptr<Device> tail_, int tailPort_) {
  head = head_;
  headPort = headPort_;
  tail = tail_;
  tailPort = tailPort_;
}

Wire::~Wire() {
}

std::shared_ptr<Device> Wire::getHead() const{
  return head;
}

void Wire::setHead(std::shared_ptr<Device> device) {
  head = device;
}

int Wire::getHeadPort() const{
  return headPort;
}

void Wire::setHeadPort(int headPort_) {
  headPort = headPort_;
}

std::shared_ptr<Device> Wire::getTail() const{
  return tail;
}

void Wire::setTail(std::shared_ptr<Device> device) {
  tail = device;
}

int Wire::getTailPort() const{
  return tailPort;
}

void Wire::setTailPort(int tailPort_) {
  tailPort = tailPort_;
}

void Wire::sendFrame(std::shared_ptr<Frame> frame) {
  tail->receiveFrame(frame, tailPort);
}
