Project 3 - Unit Conversion Program

Files:
    convert.c       Main program and user interaction
    conversion.c   Functions for reading files and performing conversions
    conversion.h   Structs and function prototypes
    Makefile        Builds the executable named convert

Compilation:
    make

This creates an executable named:
    convert

Running without flags:
    ./convert unit_conversions.txt same_names.txt

Running with short flags:
    ./convert -c unit_conversions.txt -s same_names.txt
    ./convert -s same_names.txt -c unit_conversions.txt

The program also accepts the long forms:
    ./convert --same same_names.txt --convert unit_conversions.txt

The program reads each input file once and stores the conversion
information in arrays of structs. It accepts singular names, plural
names, and abbreviations for units.

The program only performs direct conversions listed in the conversion
file. It does not chain multiple conversions.

Enter a negative value to end the program.

Example:
    Enter your desired conversion (-1 to end)
    Enter the first value: 18 inches
    Enter the desired units: foot
    There are 1.50 foot in 18.00 inches.
