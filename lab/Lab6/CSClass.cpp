#include "CSClass.h"

// Method to display class details
void CSClass::display() {
    std::cout << "Class Name: " << name << std::endl;
    std::cout << "Class Size: " << size << std::endl;
    std::cout << "Course Number: " << courseNumber << std::endl;
}

void CSClass::setClassDetails(std::string n, int s, int c) {
    name = n;
    size = s;
    courseNumber = c;
}

void CSClass::setName(std::string n) {
    name = n;
}

void CSClass::setNumber(int num) {
    courseNumber = num;
}

void CSClass::setSize(int newSize) {
    size = newSize;
}

std::string CSClass::getName() {
    return name;
}

int CSClass::getNumber() {
    return courseNumber;
}

int CSClass::getSize() {
    return size;
}