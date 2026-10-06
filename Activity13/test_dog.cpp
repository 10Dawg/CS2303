// C++ program to demonstrate protected members

#include <iostream>
#include <string>
#include "Dog.h"

int main() {
    // Create object of the Dog class
    Dog dog1;

    dog1.setType("mammal");
    dog1.setColor("black");
    dog1.eat();
    dog1.sleep();
    dog1.bark();

    // Using getColor() of dog1 as argument
    // getColor() returns string data
    dog1.displayInfo(dog1.getColor());

    return 0;
}