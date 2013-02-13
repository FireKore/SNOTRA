#ifndef __FRAME_H__
#define __FRAME_H__

#include <list>
#include <iostream>

#include "Ip.h"
#include "Mac.h"

class Frame {
 public:
  Frame(Frame* data, int i);
  void addData(unsigned char* data);
  void addIp(Ip ip, int i);
  void addMac(Mac ma, int i);
  void addProtocol(unsigned char c);
  void print();

 private:
  std::list<unsigned char> header;
  Frame* data;

  int printBlocType(unsigned char c);
  void printFrameType(unsigned char c);
  std::list<unsigned char>::iterator printAddressBloc(std::list<unsigned char>::iterator it);
  void printProtocolBloc(unsigned char c);
  std::list<unsigned char>::iterator printDataBloc(std::list<unsigned char>::iterator it, int size);
};

#endif
