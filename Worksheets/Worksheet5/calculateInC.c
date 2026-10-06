#include <stdio.h>

float get_average(float, float, float);

int main(void){
    float x, y, z;
    printf("Please enter 3 numbers\n");
    scanf("%f %f %f", &x, &y, &z);
    float average = get_average(x, y, z);
    printf("The average is %f\n", average);

    return 0;
}


float get_average(float a, float b, float c){
    float total = a + b + c;
    return total/3.0;
}