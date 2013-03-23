#include "ARPHeader.h"

ARPHeader::ARPHeader() {
}

ARPHeader::ARPHeader(std::shared_ptr<Ip> sourceIp, std::shared_ptr<Ip> destinationIp, int ttl, Protocole protocole, Mac source, Mac destination, bool isAnswer) : NetworkHeader(sourceIp, destinationIp, ttl, protocole, isAnswer) {
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
