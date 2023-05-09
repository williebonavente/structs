#include <stdio.h>

typedef struct
{
    int numerator;
    int denominator;
} fraction_t;

fraction_t get_fraction();
void print_fraction(fraction_t frac);
fraction_t reduce_fraction(fraction_t frac);

int main(void)
{
    fraction_t frac = get_fraction();

    printf("Original fraction: ");
    print_fraction(frac);

    printf(" = ");

    printf("Reduced fraction: ");
    print_fraction(reduce_fraction(frac));

    return 0;
}

fraction_t get_fraction()
{
    fraction_t frac;

    printf("Enter numerator: ");
    scanf("%d", &frac.numerator);

    printf("Enter denominator: ");
    scanf("%d", &frac.denominator);

    return frac;
}

void print_fraction(fraction_t frac)
{
    printf("%d/%d", frac.numerator, frac.denominator);
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

fraction_t reduce_fraction(fraction_t frac)
{
    int common_divisor = gcd(frac.numerator, frac.denominator);

    frac.numerator /= common_divisor;
    frac.denominator /= common_divisor;

    return frac;
}

/*
The fraction_t struct type contains two fields:
numerator and denominator, which represent the numerator
and denominator of a fraction, respectively.
The get_fraction function prompts the user to enter the numerator
and denominator of a fraction, and returns a fraction_t struct containing those values.
The print_fraction function takes a fraction_t struct and prints
it in the form of numerator/denominator.
The reduce_fraction function takes a fraction_t struct and reduces
it to lowest terms using the Euclidean
algorithm to find the greatest common divisor of the numerator and denominator.
It then divides both the numerator and denominator by this common divisor to
obtain the reduced fraction.
In main, we get a fraction from the user using get_fraction,
print it using print_fraction, print an equals sign and call
reduce_fraction to get the reduced fraction, and print that
using print_fraction as well.
*/