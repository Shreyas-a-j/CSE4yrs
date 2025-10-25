#include <stdio.h>
#include <stdlib.h>

int main() {                     //  32,16,8421
    unsigned int a = 6;  // Binary: 0110000
    unsigned int b = 2;  // Binary: 0000000
                                  //0100
    //printf("a & b = %u\n",   a & b);   
    // printf("a | b = %u\n",   a | b);  
    // printf("a ^ b = %u\n",   a ^ b);   
    printf("a << 5 = %u\n",  a << 5); // a * 2^5
    // printf("b >> 1 = %u\n",  b >> 2); 

    return 0;
}
