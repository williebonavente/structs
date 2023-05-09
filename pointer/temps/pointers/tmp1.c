#include <stdio.h>


int main (void) {

    int v =25;
    int *ptr;

    ptr = &v;
    
    // Address
    printf("Addresses\n"); 
    printf("&v = %d, ptr =  %d\n", &v, ptr); 
    
    // Values
    printf("Values\n"); 
    printf("v = %d, ptr =  %d", v, *ptr); 

    return 0;
}