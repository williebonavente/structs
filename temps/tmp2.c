#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    char name[100];
    int age;
    float height;
    char gender[100];
};

void get_input(struct Employee *emp);
void displayInfo(struct Employee *emp);

int main(void)
{
    struct Employee emp1;
    get_input(&emp1);

    system("cls");

    printf("%s's Personal Information\n", emp1.name);
    displayInfo(&emp1); 
    return 0;
}

void displayInfo(struct Employee *emp)
{
    printf("Name: %s\nAge: %i\nHeight: %.2f\nGender: %s\n",
           emp->name, emp->age, emp->height, emp->gender);
}
void get_input(struct Employee *emp)
{
    printf("Name of employee: ");
    scanf_s("%s",&emp->name);
    printf("Age: "); 
    scanf_s("%i",&emp->age);
    printf("Height: ");
    scanf_s("%f",&emp->height);
    printf("Gender: ");
    scanf_s("%s",&emp->gender);  

}