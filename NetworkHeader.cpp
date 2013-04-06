#include "NetworkHeader.h"

NetworkHeader::NetworkHeader() : Header(NETWORK, true) {
}

NetworkHeader::NetworkHeader(std::shared_ptr<Ip> source_, std::shared_ptr<Ip> destination_, int ttl, Protocole protocole_, bool isAnswer) : Header(NETWORK, isAnswer) {
  source = source_;
  destination = destination_;
  timeToLive = ttl;
  protocole = protocole_;
}

NetworkHeader::~NetworkHeader() {
}

std::shared_ptr<Ip> NetworkHeader::getSource() {
  return source;
}

void NetworkHeader::setSource(std::shared_ptr<Ip> ip) {
  source = ip;
}

std::shared_ptr<Ip> NetworkHeader::getDestination() {
  return destination;
}

void NetworkHeader::setDestination(std::shared_ptr<Ip> ip) {
  source = ip;
}

int NetworkHeader::getTimeToLive() {
  return timeToLive;
}

void NetworkHeader::decreaseTimeToLive() {
  timeToLive--;
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
