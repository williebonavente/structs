#include <stdio.h>
#include <string.h>

#define STRSIZE 10



typedef struct
{
    char name[STRSIZE];
    double diameter;
    int moons;
    double orbit_times;
    double rotation_time;
} planet_t;

typedef struct
{
    int degrees;
    int minutes;
    char direction;
} long_lat_t;

typedef struct
{
    double diameter;
    planet_t planets[9];
    char galaxy[STRSIZE];
} solar_sys_t;

int main(void)
{
    planet_t current_planet;

    // Information
    strcpy(current_planet.name, "Jupiter");
    current_planet.diameter = 142800.0;
    current_planet.moons = 16;
    current_planet.orbit_times = 11.9;
    current_planet.rotation_time = 9.925;

    printf("%s equatorial diameter is %.lf km.\n",
           current_planet.name, current_planet.diameter);
    return 0;
}