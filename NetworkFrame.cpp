#include "NetworkFrame.h"

Ip* NetworkFrame::getIpSource() {
  return ipSource;
}

void NetworkFrame::setIpSource(Ip* ip) {
  ipSource = ip;
}

Ip* NetworkFrame::getIpDest() {
  return ipDest;
}

void NetworkFrame::setIpDest(Ip* ip) {
  ipDest = ip;
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
