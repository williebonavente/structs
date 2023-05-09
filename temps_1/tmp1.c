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

int scan_planet(planet_t *plnp);
void print_planet(planet_t *pl);

int main(void)
{
    planet_t planet;

    scan_planet(&planet);

    printf("%s's Information\n", planet.name);
    print_planet(&planet);

    return 0;
}

int scan_planet(planet_t *plnp /* address of of planet_t structs */)
{
    int result;

    result = scanf("%s %lf %d %lf %lf", plnp->name,
                     &plnp->diameter,
                     &plnp->moons,
                     &plnp->orbit_times,
                     &plnp->rotation_time);

    if (result == 5)
    {
        result = 1;
    }

    else if (result != EOF)
    {
        result = 0;
    }

    return result;
}

void print_planet(planet_t *pl)
{
    printf("%s\n", pl->name);
    printf(" Equatorial diameter: %.0f km\n", pl->diameter);
    printf(" Number of Moons: %d\n", pl->moons);
    printf(" Time to complete one orbit of the sun: %.2f years\n",
           pl->orbit_times);
    printf(" Time to complete one rotation on axis: %.4f hours\n",
           pl->rotation_time);

    printf("\n");
}
