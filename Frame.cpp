#include "Frame.h"

Frame::Frame() {
}

Frame::Frame(std::shared_ptr<Frame> frame, std::shared_ptr<Header> header_, int interfaceId_) {
  data = frame;
  header = header_;
  interfaceId = interfaceId_;
}

Frame::~Frame() {
}

std::shared_ptr<Header> Frame::getHeader() {
  return header;
}

void Frame::setHeader(std::shared_ptr<Header> header_) {
  header = header_;
}

std::shared_ptr<Frame> Frame::getData() {
  return data;
}

void Frame::setData(std::shared_ptr<Frame> frame) {
  data = frame;
}

int Frame::getInterfaceId() {
  return interfaceId;
}

void Frame::setInterfaceId(int interfaceId_) {
  interfaceId = interfaceId_;
}
