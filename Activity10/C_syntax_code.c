#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/* This is an example of a C program
* CS 2303 Fall 2026
* Lecture 2, version 1
* Author: Tammy VanDeGrift
*/

/*****************************************************
 * lucky_num(int a, int b)
 * calculates and returns a lucky number given two integers
 *****************************************************/
float lucky_num(int a, int b){
   return 50.1 - a + (3 * b) ;
}

int main(int argc, char* argv){
    char fname[20];
	char lname[20];
    int age = -1;
    float lucky_number = 0;

    printf("Welcome to CS 305!\n");
    printf("Does C look like Java?\n");
    printf("What is different?\n\n");

    // acquire user's name
    printf("What is your name?\n"); 
    scanf("%s %s", fname, lname);
    printf("Welcome %s %s\n", fname, lname);
    // acquire users's age
    while(age < 0) {
        printf("What is your age?\n"); 
        scanf("%d", &age);
    }

	// Print the length of the name
	printf("%d\n", strlen(fname));
	
    // determine and print lucky number
    lucky_number = lucky_num(age, strlen(fname));
    printf("Your lucky number, %s %s, is: %.2f\n", fname, lname, lucky_number);

    return 0;
}

