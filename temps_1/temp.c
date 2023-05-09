#include <stdio.h>
#include <string.h>

#define STRSIZE 20

typedef struct
{
    char name[STRSIZE];
    double diameter;
    int moons;
    double orbit_times;
    double rotation_time;
} planet_t;

// Function prototype
void print_planet(planet_t pl);
// Comparing
int planet_equal(planet_t planet_1, planet_t planet_2);

int main(void)
{
    planet_t earth, jupyter;

    // Earth Information
    strcpy(earth.name, "Earth");
    earth.diameter = 12576;
    earth.moons = 1;
    earth.orbit_times = 365.249;
    earth.rotation_time = 1;

    // Jupiter Information
    strcpy(jupyter.name, "Jupiter");
    jupyter.diameter = 88846;
    jupyter.moons = 16;
    jupyter.orbit_times = 11.9;
    jupyter.rotation_time = 9.925;

    // Display
    print_planet(earth);
    print_planet(jupyter);

    // Comparing the planet
    planet_equal(earth, jupyter);

    return 0;
}

void print_planet(planet_t pl)
{
    printf("%s\n", pl.name);
    printf(" Equatorial diameter: %.0f km\n", pl.diameter);
    printf(" Number of Moons: %d\n", pl.moons);
    printf(" Time to complete one orbit of the sun: %.2f years\n",
           pl.orbit_times);
    printf(" Time to complete one rotation on axis: %.4f hours\n",
           pl.rotation_time);

    printf("\n");
}

int planet_equal(planet_t planet_1, planet_t planet_2)
{
    if (strcmp(planet_1.name, planet_2.name) == 0 &&
        planet_1.diameter == planet_2.diameter &&
        planet_1.moons == planet_2.moons &&
        planet_1.orbit_times == planet_2.orbit_times &&
        planet_1.rotation_time == planet_2.rotation_time)
    {
        printf("The planets %s and %s are equal.\n", planet_1.name, planet_2.name); 
    }

    else
    {
        printf("The planets %s and %s are not equal.\n", planet_1.name, planet_2.name); 
        
    }
    
}
