#ifndef __ARPTABLE_H__
#define __ARPTABLE_H__

#include <map>
#include <memory>
#include "Mac.h"
#include "Ip.h"

class ARPTable {
 public:
  ARPTable();
  virtual ~ARPTable();
  std::map<std::shared_ptr<Ip>, Mac> getAllLines();
  void resetARPTable();
  Mac getMacByIp(std::shared_ptr<Ip> ip);
  void addLine(std::shared_ptr<Ip>, Mac);
  void checkForDeletion();

 private:
  std::map<std::shared_ptr<Ip>, Mac> arpTable;

  void removeLine(std::shared_ptr<Ip>);

};

#endif
