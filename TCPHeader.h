#ifndef __TCPHEADER_H__
#define __TCPHEADER_H__

#include <string>
#include <cstring>
#include "UDPHeader.h"

class TCPHeader : public UDPHeader {
 public:
  TCPHeader();
  TCPHeader(int, int, int, int, unsigned char, bool);
  virtual ~TCPHeader();
  int getFrameNumber();
  void setFrameNumber(int);
  int getLastFrameNumber();
  void setLastFrameNumber(int);
  unsigned char getFlags();
  void setFlags(unsigned char);
  void changeFlag(std::string, bool);

 private:
  int frameNumber;
  int lastFrameNumber;
  unsigned char flags;

  void addFlag(int);
  void removeFlag(int);

};

#endif
