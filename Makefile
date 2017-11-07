CFLAGS=-c -Wall -O2

all: libtof.a

libtof.a: tof.o
	ar -rc libtof.a tof.o ;\
	sudo cp libtof.a /usr/local/lib ;\
	sudo cp tof.h /usr/local/include

tof.o: tof.c
	$(CC) $(CFLAGS) tof.c

clean:
	rm *.o libtof.a
