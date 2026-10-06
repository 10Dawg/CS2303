#include <iostream>

float get_average(float, float, float);

int main(void){
    float x, y, z;
    std::cout << "Please enter 3 numbers\n";
    std::cin >> x >> y >> z;
    std::cout << "The average is " << get_average(x, y, z) << std::endl;
    return 0;
}


float get_average(float a, float b, float c){
  return (a + b + c) / 3.0;
}