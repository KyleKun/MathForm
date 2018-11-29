CPP    = g++
RM     = rm -f
OBJS   = src/colorSet.o \
         src/ColorS.o \
         main.o

LIBS   =
CFLAGS =

.PHONY: bin/Release/gg.exe clean clean-after

all: bin/Release/gg.exe

clean:
	$(RM) $(OBJS) bin/Release/gg.exe

clean-after:
	$(RM) $(OBJS)

bin/Release/gg.exe: $(OBJS)
	$(CPP) -O2 -s -Wall -o $@ $(OBJS) $(LIBS)

src/colorSet.o: src/colorSet.cpp
	$(CPP) -O2 -s -Wall -c $< -o $@ $(CFLAGS)

src/ColorS.o: src/ColorS.cpp
	$(CPP) -O2 -s -Wall -c $< -o $@ $(CFLAGS)

main.o: main.c
	$(CPP) -O2 -s -Wall -c $< -o $@ $(CFLAGS)

