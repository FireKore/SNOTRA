#ifndef __DATALINKHEADER_H__
#define __DATALINKHEADER_H__

#include "Mac.h"

class DataLinkHeader : public Header {
 public:
  DataLinkHeader();
  virtual ~DataLinkHeader();
  Mac getSource();
  void setSource(Mac);
  Mac getDestination();
  void setDestination(Mac);

 private:
  Mac source;
  Mac destination;

};

#endif
