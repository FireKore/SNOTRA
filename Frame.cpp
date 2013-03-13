#include "Frame.h"

Frame::Frame() {
}

Frame::Frame(std::shared_ptr<Frame> frame, std::shared_ptr<Header> header_) {
  data = frame;
  header = header_;
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
