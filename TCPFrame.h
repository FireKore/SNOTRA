#ifndef __TCPFRAME_H__
#define __TCPFRAME_H__

#include <list>
#include "UDPFrame.h"
#include "enum.h"

class TCPFrame : public UDPFrame {
 public:
  TCPFrame();
  virtual ~TCPFrame();
  int getSeqNumber();
  void setSeqNumber(int);
  int getAckNumber();
  void setAckNumber(int);
  std::list<Flag> getAllFlags();
  void addFlag(Flag);

  bool isAck();
  bool isSyn();
  bool isFin();

 private:
  int seqNumber;
  int ackNumber;
  std::list<Flag> flags;

};

#endif
