#include "Header.h"

Header::Header() {
}

Header::Header(HeaderType type_, bool isAnswer_) {
  type = type_;
  isAnswer = isAnswer_;
}

Header::~Header() {
}

HeaderType Header::getType() {
  return type;
}

void Header::setType(HeaderType type_) {
  type = type_;
}

bool Header::getIsAnswer() {
  return isAnswer;
}

void Header::setIsAnswer(bool isAnswer_) {
  isAnswer = isAnswer_;
}
