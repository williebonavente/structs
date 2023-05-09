#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50

struct Book
{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
    float price;
};

void printBook(struct Book b);

int main(void)
{

    struct Book book1, book2;

    // Input for book 1
    printf("Enter title of book 1: ");
    fgets(book1.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter author of book 1: ");
    fgets(book1.author, MAX_AUTHOR_LENGTH, stdin);
    printf("Enter year of book 1: ");
    scanf_s("%d", &book1.year);
    printf("Enter the price of book 1: ");
    scanf_s("%f", &book1.price);
    getchar(); // Clear input buffer

    // Input for book 2
    printf("Enter title of book 2:");
    fgets(book2.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter author of book 2: ");
    fgets(book2.author, MAX_AUTHOR_LENGTH, stdin);
    printf("Enter year of book 2: ");
    scanf_s("%d", &book2.year);
    printf("Enter the price of book 2: ");
    scanf_s("%f", &book2.price);
    getchar(); // Clear input buffer

    // Prompting Input
    printf("\nDetails of book 1:\n");
    printBook(book1);
    printf("\nDetails of book 2:\n");
    printBook(book2);

    return 0;
}
void printBook(struct Book b)
{
    printf("\nTitle: %s", b.title);
    printf("\nAuthor: %s", b.author);
    printf("\nYear: %d", b.year);
    printf("\nPrice: %.2f", b.price);
}