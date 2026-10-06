#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/****************************
int get_numDig(int x)
input:
	x: any positive integer
returns the number of digits in x
****************************/
int get_numDig(int);

/****************************
int get_digit(int x, int y)
input:
	x: any positive integer
	y: the location of x to extract a value from
returns the integer at location y of x (counting left to right)
****************************/
int get_digit(int, int);