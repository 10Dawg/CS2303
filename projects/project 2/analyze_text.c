#include <stdio.h>
#include <string.h>
#include "analysis.h"

int main(void)
{
    char fileName[50];
    char outputName[50];
    int option;
    FILE *input;
    FILE *output;

    printf("Welcome to the text analyzer.\n");
    printf("What file would you like to read? ");
    scanf("%49s", fileName);


    printf("Which analysis would you like to run:\n");
    printf("1) Letter count\n");
    printf("2) Word length count\n");
    printf("3) Total words\n");
    printf("4) Word finder\n");
    scanf("%d", &option);

    while (option < 1 || option > 4) {
        printf("Invalid option.\n");
        printf("Please review the following options and try again.\n");
        printf("1) Letter count\n");
        printf("2) Word length count\n");
        printf("3) Total words\n");
        printf("4) Word finder\n");
        scanf("%d", &option);
    }

    if (option == 4) {
        char target[50];
        printf("Where would you like to save the results? ");
        scanf("%49s", outputName);
        input = fopen(fileName, "r");
        if (input == NULL) {
            printf("%s not found.\n", fileName);
            return 1;
        }
        printf("What word would you like to find? ");
        scanf("%49s", target);
        output = fopen(outputName, "w");
        if (output == NULL) {
            fclose(input);
            return 1;
        }
        findWord(input, output, target);
    } else {
        printf("Where would you like to save the results? ");
        scanf("%49s", outputName);
        input = fopen(fileName, "r");
        if (input == NULL) {
            printf("%s not found.\n", fileName);
            return 1;
        }
        output = fopen(outputName, "w");
        if (output == NULL) {
            fclose(input);
            return 1;
        }

        if (option == 1)
            letterCount(input, output);
        else if (option == 2)
            wordLengthCount(input, output);
        else
            totalWords(input, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}
