#include "Frame.h"

Frame::Frame(Frame* data_, int i) {
  data = data_;
  header.push_back((unsigned char)i);
}

void Frame::addData(unsigned char* data) {
  header.push_back((unsigned char)128);
  int size = 0;
  for (size = 0; data[size] != '\0'; size++) {
  }
  header.push_back((unsigned char)size);
  for(int i = 0; i < size; i++) {
    header.push_back(data[i]);
  }
}

void Frame::addIp(Ip ip, int i) {
  if(i) {
    header.push_back((unsigned char)24);
  }
  else {
    header.push_back((unsigned char)8);
  }
  for(int i = 0; i < 4; i++) {
    header.push_back(ip.getAddress()[i]);
  }
  header.push_back(ip.getMask());
}

void Frame::addMac(Mac mac, int i) {
  if(i) {
    header.push_back((unsigned char)25);
  }
  else {
    header.push_back((unsigned char)9);
  }
  for(int i = 0; i < 6; i++) {
    header.push_back(mac.getAddress()[i]);
  }
}

void Frame::addProtocol(unsigned char c) {
  header.push_back((unsigned char)64);
  header.push_back(c);
}

void Frame::print() {
  std::cout << "Displaying frame..." << std::endl << std::endl;
  for (std::list<unsigned char>::iterator it=header.begin(); it != header.end(); ++it) {
    switch(printBlocType(*it)) {
    case 0:
      ++it;
      it = printDataBloc(it, (int)*it);
      break;
    case 1:
      ++it;
      printProtocolBloc(*it);
      break;
    case 2:
      it = printAddressBloc(it);
      break;
    case 3:
      printFrameType(*it);
      break;
    }
    std::cout << std::endl;
  }
  if(data != NULL) {
    data->print();
  }
}

void Frame::printFrameType(unsigned char c) {
  switch((int)c) {
  case 1:
    std::cout << "Physical";
    break;
  case 2:
    std::cout << "Data link";
    break;
  case 3:
    std::cout << "Network";
    break;
  case 4:
    std::cout << "Transport";
    break;
  }
  std::cout << std::endl;
}

std::list<unsigned char>::iterator Frame::printAddressBloc(std::list<unsigned char>::iterator it) {
  unsigned char* address;
  if((int)(*it & (1u << 4)) == 16) {
    std::cout << "Destination : ";
  }
  else {
    std::cout << "Source : ";
  }

  if((int)(*it & 1u) == 1) {
    it++;
    address = (unsigned char*)malloc(6*sizeof(unsigned char));
    for(int i = 0; i < 5; i++) {
      address[i] = *it;
      it++;
    }
    address[5] = *it;
    Mac* mac = new Mac(address);
    mac->print();
    delete mac;
  }
  else {
    it++;
    address = (unsigned char*)malloc(4*sizeof(unsigned char));
    for(int i = 0; i < 4; i++) {
      address[i] = *it;
      it++;
    }
    Ip* ip = new Ip(address, (int)*it);
    std::cout << *ip << std::endl;
    delete ip;
  }
  return it;
}

void Frame::printProtocolBloc(unsigned char c) {
  //TODO
}

std::list<unsigned char>::iterator Frame::printDataBloc(std::list<unsigned char>::iterator it, int size) {
  it++;
  for(int i = 0; i< size - 1; i++) {
    std::cout << *it;
    ++it;
  }
  std::cout << *it << std::endl;
  return it;
}

int Frame::printBlocType(unsigned char c) {
  if((int)(c & (1u << 7)) == 128) {
    std::cout << "Data bloc" << std::endl;
    return 0;
  }
  else if((int)(c & (1u << 6)) == 64) {
    std::cout << "Protocole bloc" << std::endl;
    return 1;
  }
  else if((int)(c & (1u << 3)) == 8) {
    std::cout << "Address bloc" << std::endl;
    return 2;
  }
  else {
    std::cout << "Frame type bloc" << std::endl;
    return 3;
  }
}
