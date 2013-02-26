#include "NetworkFrame.h"

NetworkFrame::NetworkFrame() {
}

NetworkFrame::~NetworkFrame() {
}

Ip* NetworkFrame::getSourceIp() {
  return sourceIp;
}

void NetworkFrame::setSourceIp(Ip* ip) {
  sourceIp = ip;
}

Ip* NetworkFrame::getDestIp() {
  return destIp;
}

void NetworkFrame::setDestIp(Ip* ip) {
  destIp = ip;
}

int NetworkFrame::getTTL() {
  return ttl;
}

void NetworkFrame::setTTL(int ttl_) {
  ttl = ttl_;
}

Protocole NetworkFrame::getProtocole() {
  return protocole;
}

void NetworkFrame::setProtocole(Protocole prot) {
  protocole = prot;
}

TransportFrame NetworkFrame::getData() {
  return data;
}

void NetworkFrame::setData(TransportFrame data_) {
  data = data_;
}

void NetworkFrame::decrementTTL() {
  ttl--;
}

bool NetworkFrame::isAlive() {
  if(ttl)
    return true;
  else
    return false;
}
