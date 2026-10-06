#include <stdio.h> 
#include <stdlib.h>
#include "struct_functions.h"

int main(void){
    Student you = {1234, "Your Name", 4.00, SO}; 
    Student roster[1];
    roster[0] = you;
    print_student(you);

    // add code to change the GPA to 3.9

    // add code to increase class year (class_inc)

    // add code to print the roster using print_roster
    
    // print student again
    print_student(you);
}