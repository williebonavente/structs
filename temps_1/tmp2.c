#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRSIZE 20

typedef struct
{
    int degree;
    int minute;
    char direction[STRSIZE];
} long_lat_t;

// Function prototype
void print_long_lat(long_lat_t *lat_p);
void long_lat_equal(long_lat_t *lat_p1, long_lat_t *lat_p2);
int scan_long_lat(long_lat_t *lat_p);
void ver;

int main(void)
{
    long_lat_t resort_1, resort_2;

    // Getting the inputs
    scan_long_lat(&resort_1);
    printf("\n");
    scan_long_lat(&resort_2);

    system("cls");
    // Print the information
    printf("DEGREES\tMINUTE\tDIRECTION\n");
    print_long_lat(&resort_1);
    print_long_lat(&resort_2);

    // Compare
    long_lat_equal(&resort_1, &resort_2);

    return 0;
}

void print_long_lat(long_lat_t *lat_p)
{
    printf(" %i\t  %i\t  %s\n", lat_p->degree,
           lat_p->minute, lat_p->direction);
}

void long_lat_equal(long_lat_t *lat_p1, long_lat_t *lat_p2)
{
    if (lat_p1->degree == lat_p2->degree &&
        lat_p1->minute == lat_p2->minute &&
        strcasecmp(lat_p1->direction, lat_p2->direction) == 0)
    {
        printf("The coordinates are equal.\n");
    }
    else
    {
        printf("The coordinates are not equal.\n");
    }
}

int scan_long_lat(long_lat_t *lat_p)
{
    int result;
    printf("Degree, Minutes and Direction: ");
    result = scanf("%i %i %s", &lat_p->degree,
                   &lat_p->minute,
                   lat_p->direction);

    if (result == 3)
    {
        lat_p->direction[0] = toupper(lat_p->direction[0]);
        result = 1;
    }
    else if (result != EOF)
    {
        result = 0;
    }

    return result;
}

