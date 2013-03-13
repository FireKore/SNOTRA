CPPFLAGS=-g -W -Wall -Wextra -pedantic -std=c++0x

PROGS=snotra

all: $(PROGS)

snotra: Ipv4.o Ip.o Mask.o Mac.o Frame.o Header.o DataLinkHeader.o NetworkHeader.o ARPHeader.o TransportHeader.o UDPHeader.o TCPHeader.o ICMPHeader.o Device.o Hub.o Switch.o MacTable.o main.o
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
Header.o: Header.h enum.h
DataLinkHeader.o: DataLinkHeader.h Header.h Mac.h enum.h
NetworkHeader.o: NetworkHeader.h Header.h Ip.h enum.h
ARPHeader.o: ARPHeader.h NetworkHeader.h Mac.h
TransportHeader.o: TransportHeader.h Header.h enum.h
UDPHeader.o: UDPHeader.h TransportHeader.h
TCPHeader.o: TCPHeader.h UDPHeader.h
ICMPHeader.o: ICMPHeader.h TransportHeader.h Ip.h
#NetworkInterface.o: NetworkInterface.h MacTable.h EthernetFrame.h Frame.h
#ARPTable.o: ARPTable.h Mac.h Ip.h NetworkInterface.h
#RoutingTable.o: RoutingTable.h Ip.h Mask.h
Device.o: Device.h Frame.h
Hub.o: Hub.h Device.h Frame.h
Switch.o: Switch.h Frame.h MacTable.h Mac.h Device.h DataLinkHeader.h enum.h
MacTable.o: MacTable.h Mac.h Device.h
#Wire.o: Wire.h Frame.h