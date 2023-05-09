#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int u1, u2;
    int v = 3;
    int *pv; /*pointer to an integer*/
    u1 = 2 * (v + 5);
    pv = &v; /*assign address of v to pv*/
    u2 = 2 * (*pv + 5);
    printf("\nu1 = %d u2 = %d", u1, u2);
    getch();
    return 0;
}
