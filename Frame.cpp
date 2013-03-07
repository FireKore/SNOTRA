#include "Frame.h"

Frame::Frame() {
}

Frame::Frame(Frame frame) {
  header = frame.getHeader();
  data = frame.getData();
  dataLevel = frame.getDataLevel();
}

Frame::Frame(Frame* frame, Header* header_) {
  data = frame;
  header = header_;
}

Frame::~Frame() {
  delete header;
  delete data;
}

FrameType Frame::getDataLevel() {
  return dataLevel;
}

void Frame::setDataLevel(FramType level) {
  dataLevel = level;
}

Header* Frame::getHeader() {
  return header;
}

void Frame::setHeader(Header* header_) {
  header = header_;
}

Frame* Frame::getData() {
  return data;
}

void Frame::setData(Frame frame*) {
  data = frame;
}
