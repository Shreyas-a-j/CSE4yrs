#include<stdio.h>
#include<stdlib.h>

int main(){
    int x = 7;
    int *p; // declaring the pointer 
    p = &x; // assigning the address of x to pointer p
    printf("%d\n", p);
    printf("%d\n", &x);
    return 0;
}