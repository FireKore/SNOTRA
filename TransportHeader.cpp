#include "TransportHeader.h"

TransportHeader::TransportHeader() : Header(TRANSPORT, true) {
}

TransportHeader::TransportHeader(bool isAnswer) : Header(TRANSPORT, isAnswer) {
}

TransportHeader::~TransportHeader() {
}
