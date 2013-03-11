#include "DataLinkHeader.h"

DataLinkHeader::DataLinkHeader() : Header(DATALINK) {
}

DataLinkHeader::DataLinkHeader(Mac source_, Mac destination_, Type type_) : Header(DATALINK) {
  source = source_;
  destination = destination_;
  type = type_;
}

DataLinkHeader::~DataLinkHeader() {
}

Mac DataLinkHeader::getSource() {
  return source;
}

void DataLinkHeader::setSource(Mac mac) {
  source = mac;
}

Mac DataLinkHeader::getDestination() {
  return destination;
}

void DataLinkHeader::setDestination(Mac mac) {
  destination = mac;
}

Type DataLinkHeader::getType() {
  return type;
}

void DataLinkHeader::setType(Type type_) {
  type = type_;
}
