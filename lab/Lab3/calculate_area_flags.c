/* calculate_area_flags.c
* Simple program to calculate the area of right, equilateral of isosceles triangle
* Requires the use of option flags and arguments
*
* Command line arguments: 
* -t: type (right, equi, iso)
* -b: base (required for right and iso triangles)
* -h: height (required for right triangles)
* -s: side (required for equi and iso triangles)
*
* Author: Jennifer Mortensen
* Modified: 7/16/26
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void print_message(void) {
    puts("Proper usage:");
    puts("./calcTri -t type -options");
    puts("Options for type: right, equi, iso");
    puts("Additional options:");
    puts("-b <base>    base length");
    puts("-h <height>  height length");
    puts("-s <side>    side length");
}

int main(int argc, char *argv[]) {
    float base = 0;
    float height = 0;
    float side = 0;
    char *type = NULL;

    int option;

    /*
     * getopt() parses options in the form:
     * -t right -b 5 -h 10
     *
     * The colon after a letter means that option requires an argument.
     */
    while ((option = getopt(argc, argv, "t:b:h:s:")) != -1) {
        switch (option) {
            case 't':
                type = optarg;
                break;

            case 'b':
                base = atof(optarg);
                break;

            case 'h':
                height = atof(optarg);
                break;

            case 's':
                side = atof(optarg);
                break;

            case '?':
                print_message();
                return 1;

            default:
                print_message();
                return 1;
        }
    }

    /* Type is required. */
    if (type == NULL) {
        print_message();
        return 1;
    }

    /* Calculate the area. */
    float area = 0;

    if (strcmp(type, "right") == 0) {
        if (base == 0 || height == 0) {
            puts("Must have options -h and -b");
            return 1;
        }

        area = base * height * 0.5;
    }
    else if (strcmp(type, "equi") == 0) {
        if (side == 0) {
            puts("Must have option -s");
            return 1;
        }

        area = sqrt(3) / 4.0 * side * side;
    }
    else if (strcmp(type, "iso") == 0) {
        if (side == 0 || base == 0) {
            puts("Must have options -s and -b");
            return 1;
        }

        area = base / 4.0 * sqrt(4 * side * side - base * base);
    }
    else {
        puts("Invalid triangle type. Use right, equi, or iso.");
        return 1;
    }

    printf("The area is %.2f\n", area);

    return 0;
}