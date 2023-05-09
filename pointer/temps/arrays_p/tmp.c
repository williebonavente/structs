#include <stdio.h>

#define SIZE 10
int main()
{
    int x[SIZE] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int i;
    for (i = 0; i < SIZE; ++i)
    {
        printf("\ni = %5d\tx[%d] = %5d\t *(x + i) = %5d\t &(x + i) = %5x\t x + i = %5d",
               i, i, x[i], *(x + i), &x[i], *(x + i));
    }
    getch();
    return 0;
}
