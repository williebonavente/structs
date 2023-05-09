#include <stdio.h>

struct record
{
    char name[10];
    int age;
};
struct record myfriend = {"Dhang", 24};
struct record *ptrtomyfriend = &myfriend;

int main(void)
{
    /*
    Write a C statement showing how to display the value of
    first member being pointed
    by ptrtomyfriend, using ptrtomyfriend.
    */
    printf("First Value: %s", ptrtomyfriend->name);  // No.1
    printf("\nSecond Value:%i", ptrtomyfriend->age); // No.2
    
    // No. 3 
    strcpy(ptrtomyfriend->name, "NewName"); 
    ptrtomyfriend->age = 30;

    return 0;
}