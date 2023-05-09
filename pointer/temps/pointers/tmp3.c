#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 3;
    int *pa; /*pointer to an integer*/
    system("cls");
    pa = &a; /*assign address of a to pa*/
    printf("\n *pa = %5d a = % 5d", *pa, a);
    *pa = 5;
    printf("\n *pa = %5d a = % 5d", *pa, a);
    getch();
    return 1;
}
