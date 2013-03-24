#ifndef __DATALINKHEADER_H__
#define __DATALINKHEADER_H__

#include "Mac.h"
#include "Header.h"
#include "enum.h"

class DataLinkHeader : public Header {
 public:
  DataLinkHeader();
  DataLinkHeader(Mac, Mac, bool);
  virtual ~DataLinkHeader();
  Mac getSource();
  void setSource(Mac);
  Mac getDestination();
  void setDestination(Mac);
  Type getType();
  void setType(Type);

 private:
  Mac source;
  Mac destination;
  Type type;

};

#endif
