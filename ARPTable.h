#ifndef __ARPTABLE_H__
#define __ARPTABLE_H__

#include <memory>
#include <list>
#include "Mac.h"
#include "Ip.h"

class ARPTableLine {
 public:
  ARPTableLine();
  ARPTableLine(std::shared_ptr<Ip>, Mac);
  virtual ~ARPTableLine();
  std::shared_ptr<Ip> getIp();
  void setIp(std::shared_ptr<Ip>);
  Mac getMac();
  void setMac(Mac);

 private:
  std::shared_ptr<Ip> ip;
  Mac mac;
  //TODO : add the time to live

};

class ARPTable {
 public:
  ARPTable();
  virtual ~ARPTable();
  std::list<ARPTableLine> getAllLines();
  ARPTableLine getLineByIp(std::shared_ptr<Ip> ip);
  void addLine(ARPTableLine);

 private:
  std::list<ARPTableLine> arpTable;

};

#endif
