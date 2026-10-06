#include <iostream>
#include <string>
#include "CSClass.h"

int main() {

	CSClass introClasses[3];

    // Create an object of CSClass
    CSClass cs1101("Introduction to Program Design", 200, 1101);

	// copy it ito the array
	introClasses[0] = cs1101;

	// set the next items manually
	introClasses[1].setName("Object-Oriented Design Concepts");
	introClasses[1].setSize(175);
	introClasses[1].setNumber(2102);
   
	introClasses[2].setClassDetails("Systems Programming Concepts", 170, 2303);

	// Display class details
    introClasses[0].display();
	std::cout << std::endl;

	std::cout << introClasses[1].getName() << ", ";
	std::cout << introClasses[1].getSize() << ", ";
	std::cout << introClasses[1].getNumber() << std::endl;
	std::cout << std::endl;
	introClasses[2].display();


    return 0;
}
