#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void reorder(int n, int *x);

int main()
{
    int i, n, *x;
    printf("How many numbers will be entered?\n");
    scanf("%d", &n);
    printf("\n");
    x = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
    {
        printf("i = %d x = ", i + 1);
        scanf("%d", x + i);
    }
    reorder(n, x);
    printf("\n\nReordered list of numbers:\n\n");
    for (i = 0; i < n; ++i)
        printf("i = %d x = %d\n", i + 1, *(x + i));
    getch();
    return 0;
}

void reorder(int n, int *x)
{
    int i, item, temp;
    for (item = 0; item < n - 1; ++item)
        for (i = item + 1; i < n; ++i)
            if (*(x + i) < *(x + item))
            {
                temp = *(x + item);
                *(x + item) = *(x + i);
                *(x + i) = temp;
            }
}
