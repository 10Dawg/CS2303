#include <stdio.h> 
int main(void) {     
	unsigned int p = 185; // 0011 1100
    unsigned int q = 13; // 0000 1101
    int r = 0;
    r = p | q; // 0011 1101
    printf("p | q - The value of r is %d\n", r );
    
	r = p & q; // 0000 1100
    printf("p & q - The value of r is %d\n", r );
    
	r = ~p; // 1100 0011
    printf("~p - The value of r is %d\n", r );
    
	r = p ^ q; //  0011 0001
    printf("p ^ q - The value of r is %d\n", r );
    
	r = p >> 2; // 0000 1111
    printf("p >> 2 - The value of r is %d\n", r );
    
	r = p << 2;// 1111 0000
    printf("p << 2 - The value of r is %d\n", r );
	
    unsigned int mask = 12; // 0000 1100
    r = (p & mask) >> 2; // Extract bits 2 and 3
    printf("%d\n", r);

} 

