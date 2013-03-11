#include "Header.h"

Header::Header() {
}

Header::Header(HeaderType type_) {
  type = type_;
}

Header::~Header() {
}

HeaderType Header::getType() {
  return type;
}

void Header::setType(HeaderType type_) {
  type = type_;
}
