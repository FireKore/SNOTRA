CPPFLAGS=-g -Wall

PROGS=snotra

all: $(PROGS)

snotra: Ipv4.o Ip.o Mask.o Mac.o Frame.o EthernetFrame.o NetworkFrame.o ARPFrame.o TransportFrame.o UDPFrame.o TCPFrame.o ICMPFrame.o main.o
	g++ $^ -o $@

clean:
	rm -f *.o *~ log.txt

depend:
	@makedepend *.cpp -Y. > /dev/null 2>&1
# DO NOT DELETE

Main.o: Ipv4.h Mac.h
Ip.o: Ip.h
Ipv4.o: Ipv4.h Ip.h Mask.h
Mask.o: Mask.h
Mac.o: Mac.h
Frame.o: Frame.h
EthernetFrame.o: EthernetFrame.h Frame.h enum.h
NetworkFrame.o: NetworkFrame.h Frame.h enum.h
ARPFrame.o: ARPFrame.h NetworkFrame.h enum.h
TransportFrame.o : TransportFrame.h Frame.h enum.h
UDPFrame.o: UDPFrame.h TransportFrame.h enum.h
TCPFrame.o: UDPFrame.h TCPFrame.h enum.h
ICMPFrame.o: ICMPFrame.h TransportFrame.h enum.h
