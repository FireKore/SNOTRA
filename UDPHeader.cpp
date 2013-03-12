#include "UDPHeader.h"

UDPHeader::UDPHeader() {
}

UDPHeader::UDPHeader(int source, int destination, bool isAnswer) : TransportHeader(isAnswer) {
  sourcePort = source;
  destinationPort = destination;
}

UDPHeader::~UDPHeader() {
}

int UDPHeader::getSourcePort() {
  return sourcePort;
}

void UDPHeader::setSourcePort(int port) {
  sourcePort = port;
}

int UDPHeader::getDestinationPort() {
  return destinationPort;
}

void UDPHeader::setDestinationPort(int port) {
  destinationPort = port;
}
