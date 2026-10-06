#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    float b = -1, h = -1, a = -1;
    while(b < 0) {
        printf("Enter the base: ");
        scanf("%f", &b);
        if(b < 0) printf("Value must be positive.\n");
    }
    while(h < 0) {
        printf("Enter the height: ");
        scanf("%f", &h);
        if(h < 0) printf("Value must be positive.\n");
    }
    a = (b * h) / 2;
    printf("The area is %.2f.\n", a);
    return 0;
}
