CC = gcc
CFLAGS = -Wall -Wextra -std=c11

analyzeText: analyze_text.o analysis.o clean_word.o
	gcc -o analyzeText analyze_text.o analysis.o clean_word.o

analyze_text.o: analyze_text.c analysis.h
	gcc -c analyze_text.c

analysis.o: analysis.c analysis.h clean_word.h
	gcc -c analysis.c

clean_word.o: clean_word.c clean_word.h
	gcc -c clean_word.c

clean:
	rm -f *.o analyzeText
