#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void tower(int n, int source, int temp, int destination){
    if(n==0){
        return;
    }
    tower(n-1,source,destination,temp);
    printf("Move %d from %c to %c\n",n,source,destination);
    tower(n-1,temp,source,destination);
}
void main(){
    printf("Enter the number of discs: ");
    int n;
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("\nTotal number of moves are %d",(int)n*n-1);
}
