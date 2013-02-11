#include "Ip.h"
#include "Mac.h"
#include "Frame.h"

int main(int argc, char** argv) {
  std::string str = "192.168.1.1", str2 = "192.168.1.3";
  Ip* ip1 = new Ip(str, 12);
  Ip* ip2 = new Ip(str2, 12);
  ip1->print();
  ip2->print();
  Mac* mac = new Mac("0e:ff:c1:54:00:ab");
  Mac* mac2 = new Mac("0e:ff:c1:54:00:ae");
  mac->print();
  mac2->print();

  std::cout << std::endl;

  Frame* frame2 = new Frame(NULL, 2);
  char* str3 = "Hello world";
  unsigned char* str4 = reinterpret_cast<unsigned char*>(str3);
  frame2->addData(str4);

  Frame* frame =  new Frame(frame2, 1);
  frame->addIp(*ip1, 1);
  frame->addIp(*ip2, 0);
  frame->addMac(*mac, 0);
  frame->addMac(*mac2, 1);

  frame->print();

  delete mac;
  delete mac2;
  delete ip1;
  delete ip2;
  delete frame;
  delete frame2;
}
