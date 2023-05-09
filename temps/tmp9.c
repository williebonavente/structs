#include <stdio.h>
#include <string.h>
#include <string.h>

#define STRSIZE 20

typedef struct
{
    char name[STRSIZE];
    char publisher[STRSIZE];
    int year;

} catalog_entry_t;

int main(void)
{

    catalog_entry_t book;

    strcpy(book.name, "C Book");
    strcpy(book.publisher, "Dennis Ritchie");
    book.year = 1972;

    printf("%s\n%s\n%i", strcpy(book.name, "C Book"),
           strcpy(book.publisher, "Dennis Ritchie"),
           book.year = 1972);

    return 0;
}