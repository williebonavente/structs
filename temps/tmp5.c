#include<stdio.h>
#include<string.h>

struct record // global template of structure record
{
    char name[30];
    int age;
};

void funct(struct record paramrec); // function prototype with structure as argument

int main()
{

    struct record argrec;
    argrec.age = 23;
    printf("Enter name >> "); 
    scanf_s("%s",&argrec.name, 30);
    funct(argrec); // function call passing structure argrec

    return 0;
}

void funct(struct record paramrec)
{
    printf("%s\n", paramrec.name); // prints "Arnie" on the screen
    printf("%d ", paramrec.age); // prints 23 on the screen
}
