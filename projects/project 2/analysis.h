#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <stdio.h>

void letterCount(FILE *input, FILE *output);
void wordLengthCount(FILE *input, FILE *output);
void totalWords(FILE *input, FILE *output);
void findWord(FILE *input, FILE *output, const char target[]);

#endif
