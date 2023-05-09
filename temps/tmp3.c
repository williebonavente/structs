#include <stdio.h>
#include <string.h>

struct record
{
    char name[100];
    int age;
};


//
typedef struct 
{
    int studentID; // STUDENT ID
    char firstName[50]; // FIRST NAME
    char lastName[50]; // LAST NAME
    int totalUnitsCompleted; // TOTAL UNITS
    float accumulatedGPA; // GGEZ
}StudentRecord;

// Display Info
void display_info(struct record *info);
void get_input(struct record *info);

int main(void)
{
    struct record info1;
    get_input(&info1);

    display_info(&info1);

    return 0;
}

void display_info(struct record *info)
{
    printf("%s\n", info->name);
    printf("%d", info->age);
}

void get_input(struct record *info)
{
    printf("Enter name >> ");
    scanf_s("%s", info->name, 100);
    printf("Enter age >> ");
    scanf_s("%d", &info->age);
}
