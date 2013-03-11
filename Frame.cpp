#include "Frame.h"

Frame::Frame() {
}

Frame::Frame(const Frame& frame) : data(new Frame()), header(frame.header) {
  data = frame.data;
  }

Frame::Frame(Frame* frame, Header header_) {
  data = frame;
  header = header_;
}

Frame::~Frame() {
  delete data;
}

Header Frame::getHeader() {
  return header;
}

void Frame::setHeader(Header header_) {
  header = header_;
}

Frame* Frame::getData() {
  return data;
}

void Frame::setData(Frame* frame) {
  data = frame;
}
