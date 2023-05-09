#include <stdio.h>
#include <conio.h>

struct product
{
    char pname[30];
    int num;
    float bill, price;
};

void funct(struct product two[]);

int main()
{
    struct product one[2];
    float product_price;
    int a;

    for (a = 0; a < 2; a++)
    {
        printf("\nEnter product name: ");
        scanf("%s", one[a].pname);

        printf("\nEnter Quantity ");
        scanf("%d", &one[a].num);

        printf("\nEnter Price: ");
        scanf("%f", &product_price);
        one[a].price = product_price;
        one[a].bill = one[a].num * one[a].price;
    }

    funct(one);
    printf("\n"); 
    return 0;
}

void funct(struct product two[])
{
    int a;
    float tbill = 0.00;

    for (a = 0; a < 2; a++)
        tbill = tbill + two[a].bill;

    printf("\nValues of the records are:\n\n");
    
    for (a = 0; a < 2; a++)
        printf("Product Name: %s\t  Quantity: %d\t  Price:%.2f\n",
               two[a].pname, two[a].num, two[a].price);

    printf("\nTotal bill is %.2f", tbill);
}
