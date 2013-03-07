#include "NetworkHeader.h"

NetworkHeader::NetworkHeader() {
}

NetworkHeader::NetworkHeader(NetworkHeader header) {
  source = header.getSource();
  destination = header.getDestination();
  timeToLive = header.getTimeToLive();
}
