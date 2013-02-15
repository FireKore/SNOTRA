CPPFLAGS=-g -Wall

PROGS=snotra

all: $(PROGS)

snotra: Ipv4.o Mask.o Mac.o main.o
	g++ $^ -o $@

clean:
	rm -f *.o *~ log.txt

depend:
	@makedepend *.cpp -Y. > /dev/null 2>&1
# DO NOT DELETE

Main.o: Ipv4.h Mac.h
Ip.o: Ipv4.h Ip.h Mask.h
Mask.o: Mask.h
Mac.o: Mac.h
