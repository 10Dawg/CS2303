#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;



/*****************************************************
 * lucky_num(int a, int b)
 * calculates and returns a lucky number given two integers
 *****************************************************/
float lucky_num(int a, int b){
   return 50.1 - a + (3 * b) ;
}

int main(int argc, char* argv[]){
    string fname;
	string lname;
    int age = -1;
    float lucky_number = 0;
    
    std::cout << "Welcome to C++!" << std::endl;
    cout << "Does C++ look like C?\n";
    cout <<"What is different?" << endl << endl;

    // acquire user's name
    cout << "What is your name?" << endl; 
    cin >> fname >> lname;
    cout << "Welcome " << fname << " " << lname << endl;
    // acquire users's age
    while(age < 0) {
        cout << "What is your age?" << endl;
        cin >> age;
    }

	// Print the length of the name
	cout << fname.length() << endl;
	
    // determine and print lucky number
    lucky_number = lucky_num(age, fname.length());
    cout << "Your lucky number, " << fname << " " << lname <<  ", is: " << lucky_number << endl;

    return 0;
}

