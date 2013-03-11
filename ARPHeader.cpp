#include "ARPHeader.h"

ARPHeader::ARPHeader() {
}

ARPHeader::ARPHeader(Ip sourceIp, Ip destinationIp, int ttl, Protocole protocole, Mac source, Mac destination) : NetworkHeader(sourceIp, destinationIp, ttl, protocole) {
  sourceMac = source;
  destinationMac = destination;
}

ARPHeader::~ARPHeader() {
}

Mac ARPHeader::getSourceMac() {
  return sourceMac;
}

void ARPHeader::setSourceMac(Mac mac) {
  sourceMac = mac;
}

Mac ARPHeader::getDestinationMac() {
  return destinationMac;
}

void ARPHeader::setDestinationMac(Mac mac) {
  destinationMac = mac;
}
