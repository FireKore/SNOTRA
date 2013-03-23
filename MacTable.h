#ifndef __MACTABLE_H__
#define __MACTABLE_H__

#include <list>
#include <map>
#include "Mac.h"

class MacTable {
 public:
  MacTable();
  MacTable(int);
  virtual ~MacTable();
  std::map<int, std::list<Mac>> getAllLines();
  void resetMacTable();
  int containsMac(Mac);
  void saveMac(Mac, int);
  void checkForDeletion();

 private:
  std::map<int, std::list<Mac>> macTable;

  void addMac(Mac, int);
  void removeMac(Mac, int);

};

#endif
