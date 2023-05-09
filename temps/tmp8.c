#include <stdio.h>
#include <string.h>

#define STRSIZE 20

typedef struct
{
    int degree;
    int minute;
    char direction;
} long_lat_t;

typedef struct
{
    char place[STRSIZE];
    long_lat_t longitude,
        latitude;
} location_t;

int main(void)
{
    location_t resort;
    resort.longitude.degree = 158;
    resort.longitude.minute = 0;
    resort.longitude.direction = 'W';

    printf("%s\n%i\n%i\n%c ", strcpy(resort.place, "Hawaii"),
           resort.longitude.degree, resort.longitude.minute, resort.longitude.direction);

    return 0;
}