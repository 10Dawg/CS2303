runCode: myCode.o fun.o myMath.o
	gcc -g -Wall fun.o myCode.o myMath.o -lm -o runCode 

myCode.o: myCode.c
	gcc -g -Wall -c myCode.c

myMath.o: myMath.h myMath.c
	gcc -g -Wall -c myMath.c

fun.o: fun.h fun.c
	gcc -g -Wall -c fun.c

clean:
	rm -f fun.o myMath.o myCode.o runCode

all: runCode