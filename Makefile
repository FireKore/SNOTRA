CPPFLAGS=-g -Wall

PROGS=snotra

all: $(PROGS)

snotra: Ipv4.o Ip.o Mask.o Mac.o Frame.o NetworkInterface.o MacTable.o ARPTable.o RoutingTable.o Device.o Wire.o main.o
	g++ $^ -o $@

clean:
	rm -f *.o *~ log.txt

depend:
	@makedepend *.cpp -Y. > /dev/null 2>&1
# DO NOT DELETE

Main.o: 
Ip.o: Ip.h Mask.h
Ipv4.o: Ipv4.h Ip.h
Mask.o: Mask.h
Mac.o: Mac.h
Frame.o: Frame.h Header.h
NetworkInterface.o: NetworkInterface.h MacTable.h EthernetFrame.h Frame.h
MacTable.o: MacTable.h Mac.h Wire.h
ARPTable.o: ARPTable.h Mac.h Ip.h NetworkInterface.h
RoutingTable.o: RoutingTable.h Ip.h Mask.h
Device.o: Device.h Frame.h enum.h
Wire.o: Wire.h Frame.h