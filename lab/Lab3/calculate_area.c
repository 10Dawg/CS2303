/* calculate_area.c
* Simple program to calculate the area of right, equilateral of isosceles triangle
* 
* Run with 3 command line arguments
* ./run type length1 length2 
* where type is right, equi or iso
*
* Author: Jennifer Mortensen
* Modified: 7/16/26
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	// Check for the correct number of arguments
    if (argc != 4){
        puts("Wrong number of command line arguments");
        puts("Proper usage:");
        puts("./calcTri type length1 length2");
        puts("Options for type: right, equi, iso");
        return 0;
    }

	// convert lengths to floats
    float length1 = atof(argv[2]);
    float length2 = atof(argv[3]);
    
	// Calculate area based on triangle type
	float area = 0;
    if (strcmp(argv[1], "right") == 0){
        area = length1 * length2 * 0.5;
    }
    else if (strcmp(argv[1], "equi") == 0){
        area = sqrt(3)/4.0*length1*length1;
    }
    else if (strcmp(argv[1], "iso") == 0){
        if (length1 == length2){
            puts("Area can not be calculated");
            puts("Enter the length of the side and base");
            return 0;
        }
        float base = 0;
        float side = 0;

        // defaults to length1 as the base if length1 < 2*side
        if (length1 < length2*2){ // length2 is the sides, length1 is the base
            base = length1;
            side = length2;
        }
        else{
			// length2 is the base 
            base = length2;
            side = length1;
        }
        area = base/4.0 * sqrt(4*side*side - base*base); 
    }
    printf("The area is %.2f\n", area);
    return 0;
}