#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main()
{
    char str[80], *p;
    printf("Enter a string in uppercase: ");
    gets(str);
    printf("Here's the string in lowercase: ");
    p = str;
    while (*p)
        printf("%c", tolower(*p++));
    getch();
    return 0;
}
