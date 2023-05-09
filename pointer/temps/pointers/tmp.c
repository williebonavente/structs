#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int u = 2;
    unsigned int v;
    unsigned int *pu; /*pointer to an unsigned integer*/
    unsigned int *pv; /*pointer to an unsigned integer*/
    pu = &u;          /*assign address of u to pu*/
    v = *pu;          /*assign value pointed to by pu to v*/
    pv = &v;          /*assign address of v to pv*/
    printf("\nu = %u &u = %p pu = %p *pu = %u", u, (void *)&u, (void *)pu, *pu);
    printf("\n\nv = %u &v = %p pv = %p *pv = %u", v, (void *)&v, (void *)pv, *pv);
    return 0;
}
