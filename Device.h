#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <list>
#include "Frame.h"
#include "NetworkInterface.h"

class Wire;

class Device {
 public:
  Device();
  virtual ~Device();
  std::list<Frame*> getAllFrameHistory();
  void addFrameToHistory(Frame*);
  std::list<Frame*> getFrameHistoryByDestIp(Ip*);
  std::list<Frame*> getFrameHistoryBySourceIp(Ip*);
  std::list<Frame*> getFrameHistoryByDestMac(Mac);
  std::list<Frame*> getFrameHistoryBySourceMac(Mac);

  void receiveFrame(Frame*);
  Frame* createFrame(Ip*);

 private:
  std::list<Frame*> frameHistory;

};

#endif
