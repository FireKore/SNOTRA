#include "DataLinkHeader.h"

DataLinkHeader::DataLinkHeader() {
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
