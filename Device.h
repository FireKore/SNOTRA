#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <list>
#include "Frame.h"
#include "enum.h"

class Device {
 public:
  Device();
  virtual ~Device();
  std::list<Frame*> getAllFrameHistory();
  void addFrameToHistory(Frame*);
  std::list<Frame*> getFrameHistoryByType(FrameType);
  std::list<Frame*> getFrameHistoryByProtocole(Protocole);
  std::list<Frame*> getFrameHistoryByDestIp(Ip*);
  std::list<Frame*> getFrameHistoryBySourceIp(Ip*);
  std::list<Frame*> getFrameHistoryByDestMac(Mac);
  std::list<Frame*> getFrameHistoryBySourceMac(Mac);

 private:
  std::list<Frame*> frameHistory;

};

#endif
