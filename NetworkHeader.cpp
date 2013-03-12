#include "NetworkHeader.h"

NetworkHeader::NetworkHeader() : Header(NETWORK, true) {
}

NetworkHeader::NetworkHeader(Ip source_, Ip destination_, int ttl, Protocole protocole_, bool isAnswer) : Header(NETWORK, isAnswer) {
  source = source_;
  destination = destination_;
  timeToLive = ttl;
  protocole = protocole_;
}

NetworkHeader::~NetworkHeader() {
}

Ip NetworkHeader::getSource() {
  return source;
}

void NetworkHeader::setSource(Ip ip) {
  source = ip;
}

Ip NetworkHeader::getDestination() {
  return destination;
}

void NetworkHeader::setDestination(Ip ip) {
  source = ip;
}

int NetworkHeader::getTimeToLive() {
  return timeToLive;
}

void NetworkHeader::setTimeToLive(int ttl) {
  timeToLive = ttl;
}

Protocole NetworkHeader::getProtocole() {
  return protocole;
}

void NetworkHeader::setProtocole(Protocole protocole_) {
  protocole = protocole_;
}
