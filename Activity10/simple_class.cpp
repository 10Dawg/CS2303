#include <string> 
#include <iostream>
using namespace std;
#include "struct_functions.h"
#include "student_class.h"

int main(void){
    Student you(1234, "Your Name", 4.00, SO);
	Student other(1235, "Their Name", 4.00, SR);  
    Student temp();

    Student temp1(1236, "Temp Name");

	cout << "Print starting student." << endl;
    you.print_student();

	you.update_gpa(3.9);

    int status = you.class_inc();
	if (status != 0){
		cout << "Problem updating year" << endl;
	}
	cout << "Print modified student." << endl;
    
    you.print_student();

    Student roster[2];
    roster[0] = you;
	roster[1] = other;
	cout << endl<<"Print the roster" << endl;
    print_roster(roster, 2);
}