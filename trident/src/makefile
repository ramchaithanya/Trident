OBJS	= tridentmain.o
CC	= g++
DEBUG	= -g
CFLAGS	= -Wall -c $(DEBUG) 
CFLAGS	+= `wx-config --cxxflags`
CFLAGS	+= `pkg-config --cflags opencv`
LIBS	 = `wx-config --libs`
LIBS    += `pkg-config --libs opencv`



trident		: $(OBJS)
	$(CC)  $(LIBS) $(OBJS) -o trident

tridentmain.o	: tridentmain.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) tridentmain.cpp

clean:
	\rm -rvf *.o *~ p1
