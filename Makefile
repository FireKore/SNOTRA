CPPFLAGS=-g -Wall

PROGS=snotra

all: $(PROGS)

snotra: Ip.o Mac.o Frame.o main.o
	g++ $^ -o $@

clean:
	rm -f *.o *~ log.txt

depend:
	@makedepend *.cpp -Y. > /dev/null 2>&1
# DO NOT DELETE

Main.o: Ip.h Mac.h
Ip.o: Ip.h
Mac.o: Mac.h
Frame.o: Frame.h Ip.h Mac.h
