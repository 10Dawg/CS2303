# This makefile is used as follows to regenerate files for the sinewave program:
#   make intarray.o   --  Regenerates intarray.o by compiling
#   make sinewave.o   --  Regenerates sinewave.o by compiling
#   make sinewave     --  Regenerates the executable sinewave file by compiling
#   make              --  Same as "make sinewave"
#

sinewave: intarray.o sinewave.o
	gcc -g -Wall sinewave.o intarray.o -lm -o sinewave 

intarray.o: intarray.h intarray.c
	gcc -g -Wall -c intarray.c

sinewave.o: intarray.h sinewave.c
	gcc -g -Wall -c sinewave.c

clean:
	rm -f sinewave.o intarray.o sinewave

all: sinewave
