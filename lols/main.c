/*
BONAVENTE, WILLIE M.
BSIT 1-5
*/
#include <stdio.h>
#include <stdlib.h> // added for malloc and free
// macro value for a maximum value of the user allowed to input.
#define MAX_ROWS 100
#define MAX_COLS 100
/*
Function prototypes listed all of the following parameters and
the return value if any.
*/

/// @brief
/// @param rows
/// @param cols
/// @return
// Input evaluation for the user scanning for the error in the size.
int scanArraySize(int *rows, int *cols);
/// @brief
/// @param arr
/// @param rows
/// @param cols
// scanning error
void scanArrayElements(int **arr, int rows, int cols);
/// @brief
/// @param arr
/// @param rows
/// @param cols
/// @param min
/// @param max
// Function prototype for searching.
void findMinMaxArray(int **arr, int rows, int cols, int *min, int *max);
int main()
{
    // 2d array declaration
    int **arr;
    int rows; // input - outer part of the array
    int cols; // input - inner part of the array.
    int min;  // output - argument to fuction.
    int max;  // output - argument to function.
    int i; // index looping variable.
    // scanning the size of array for errors.
    if (!scanArraySize(&rows, &cols))
    {
        printf("Invalid input for array size.\n");
        return 1;
    }
    // dynamic memory allocation for 2D array
    arr = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    // scanning each element for errors.
    scanArrayElements(arr, rows, cols);
    // function call to find the min and max value of the array.
    findMinMaxArray(arr, rows, cols, &min, &max);
    // Prompt the output.
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    // Free the dynamically allocated memory
    for (i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
/*
This function scans the number of rows and columns for a 2D array from the
user. It takes two pointers to integers as input arguments, which are used to

store the number of rows and columns input by the user.
*/
int scanArraySize(int *rows, int *cols)
{
    printf("Enter number of rows: ");
    // setting up the contingencies.
    if (scanf("%d", rows) != 1 || *rows < 1 || *rows > MAX_ROWS)
    {
        return 0;
    }
    printf("Enter number of columns: ");
    if (scanf("%d", cols) != 1 || *cols < 1 || *cols > MAX_COLS)
    {
        return 0;
    }
    return 1;
}
/*
This function scans the elements of a 2D array from the user. It takes a
two dimensional array arr of integers, and the number of rows and columns of
that
array, rows, and cols, respectively.
*/
void scanArrayElements(int **arr, int rows, int cols)
{
    // index looping variable
    int i, j;
    printf("Enter array elements:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            // scan each element of the array

            if (scanf("%d", &arr[i][j]) != 1)
            {
                printf("Invalid input for array element.\n");
                exit(1);
            }
        }
    }
}
/*
This function finds the minimum and maximum elements of a 2D array.
It takes a two-dimensional array arr of integers, and the number of rows
and columns of that array, rows, and cols, respectively. It also takes two
pointers
to integers, min and max, which are used to store the minimum and maximum
elements
of the array, respectively.
*/
void findMinMaxArray(int **arr, int rows, int cols, int *min, int *max)
{
    // index looping variable
    int i, j;
    // initialize min and max to the first element of the array
    *min = arr[0][0];
    *max = arr[0][0];
    // iterate over each element of the array
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {

            // update min if current element is less than min
            if (arr[i][j] < *min)
            {
                *min = arr[i][j];
            }

            // update max if current element is greater than max

            if (arr[i][j] > *max)
            {
                *max = arr[i][j];
            }
        }
    }
    // iterate over each element of the array
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {

            // update min if current element is less than min
            if (arr[i][j] < *min)
            {
                *min = arr[i][j];
            }

            // update max if current element is greater than max

            if (arr[i][j] > *max)
            {
                *max = arr[i][j];
            }
        }
    }
}