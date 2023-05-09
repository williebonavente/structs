#include <stdio.h>
int array[] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int idx;
int main()
{
    idx = 0;
    while (array[idx] != 0)
        ++idx;
    printf("Number of elements before zero: %d\n", idx);
    return 0;
}
