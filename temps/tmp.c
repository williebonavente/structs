#include <stdio.h>
#include <string.h>

struct person
{
    char name[50];
    int age;
    float height;
};


void printPerson(struct person *p)
{
    printf("Name: %s\nAge: %d: \nHeight: %.2f\n", p->name, p->age, p->height); 
}

int main (void) {

    struct person p1;
    strcpy(p1.name, "John");
    p1.age = 50;
    p1.height = 1.6;
    printPerson(&p1);

    return 0;
}