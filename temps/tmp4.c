#include <stdio.h>
#include <conio.h>
#include <string.h>

struct date
{
    int month, day, year;
};

struct record
{
    char name[30];
    int age;
    struct date bdate;
};

int main()
{
    struct record mypal;
    int ctr;


    for (ctr = 0; ctr < 5; ctr++)
    {
        printf("Enter name: ");
        fgets(mypal.name, 30, stdin);
        mypal.name[strcspn(mypal.name, "\n")] = '\0'; // remove the newline character

        printf("Enter age: ");
        scanf("%d", &mypal.age);
        fflush(stdin);

        printf("Enter birthdate month in number: ");
        scanf("%d", &mypal.bdate.month);
        fflush(stdin);

        printf("Enter birthdate day in number: ");
        scanf("%d", &mypal.bdate.day);
        fflush(stdin);

        printf("Enter birthdate year in number: ");
        scanf("%d", &mypal.bdate.year);
        fflush(stdin);

        printf("Hello %s!\n", mypal.name);
        printf("Your birthday is on %d-%d-%d!\n", mypal.bdate.month, mypal.bdate.day, mypal.bdate.year);
        printf("Wow, you'll be %d soon!\n\n", mypal.age + 1);
    }

    getch();
    return 0;
}
