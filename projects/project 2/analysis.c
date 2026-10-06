#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "analysis.h"
#include "clean_word.h"

static void makeLower(char word[])
{
    int i = 0;
    while (word[i] != '\0') {
        word[i] = (char)tolower((unsigned char)word[i]);
        i++;
    }
}

void letterCount(FILE *input, FILE *output)
{
    int counts[26] = {0};
    char word[50];
    int i;
    int index;

    while (fscanf(input, "%49s", word) == 1) {
        cleanWord(word);
        for (i = 0; word[i] != '\0'; i++) {
            if (isalpha((unsigned char)word[i])) {
                index = tolower((unsigned char)word[i]) - 'a';
                if (index >= 0 && index < 26)
                    counts[index]++;
            }
        }
    }
    for (i = 0; i < 26; i++)
        fprintf(output, "%c %d\n", 'a' + i, counts[i]);
}

void wordLengthCount(FILE *input, FILE *output)
{
    int counts[16] = {0};
    char word[50];
    int length;

    while (fscanf(input, "%49s", word) == 1) {
        cleanWord(word);
        length = (int)strlen(word);

        if (length > 0) {
            if (length >= 16)
                counts[15]++;
            else
                counts[length - 1]++;
        }
    }
    for (length = 1; length <= 15; length++)
        fprintf(output, "%d %d\n", length, counts[length - 1]);
}

void totalWords(FILE *input, FILE *output)
{
    char word[50];
    int total = 0;

    while (fscanf(input, "%49s", word) == 1) {
        cleanWord(word);
        if (strlen(word) > 0)
            total++;
    }

    fprintf(output, "The file has %d words.\n", total);
}

void findWord(FILE *input, FILE *output, const char target[])
{
    char word[50];
    char cleanedTarget[50];
    int count = 0;

    strncpy(cleanedTarget, target, 49);
    cleanedTarget[49] = '\0';
    cleanWord(cleanedTarget);
    makeLower(cleanedTarget);

    while (fscanf(input, "%49s", word) == 1) {
        cleanWord(word);
        makeLower(word);
        if (strlen(word) > 0 && strcmp(word, cleanedTarget) == 0)
            count++;
    }

    fprintf(output, "The word '%s' appears %d times.\n", cleanedTarget, count);
}
