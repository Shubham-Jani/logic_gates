#include <stdio.h>
#include <stdlib.h>
#include "line.h"
int a = 0, b = 1;
int not(int a)
{
    if (a == 0)
        return 1;
    else
        return 0;
};
int or (int a, int b)
{
    return (a || b);
}
int and (int a, int b)
{
    return (a && b);
}
int nand(int a, int b)
{
    int buffer = and(a, b);
    return not(buffer);
}
int nor(int a, int b)
{
    int buffer = or (a, b);
    return not(buffer);
}

void cases(int i)
{
    switch (i)
    {
    case 1:
        printf("output of not %d: %d\n", a, not(a));
        printf("output of not %d: %d\n", b, not(b));
        break;
    case 2:
        printf("output of %d nor %d: %d\n", a, b, nor(a, b));
        break;
    case 3:
        printf("output of %d or %d: %d\n", a, b, or (a, b));
        break;
    case 4:
        printf("output of %d and %d : %d\n", a, b, and(a, b));
        break;
    case 5:
        printf("output of %d nand %d: %d\n", a, b, nand(a, b));
        break;
    }
}

void withInput()
{
    printf("Enter value of a and b (values must be 0 or 1)\n");
    printf("a : ");
    scanf("%d", &a);
    printf("b : ");
    scanf("%d", &b);
    if ((a != 0 && a != 1) || (b != 0 && b != 1))
        printf("\nyou had one job and you failed\n");
    else
    {
        int *i;
        i = (int *)malloc(sizeof(int));
        printf("Which gate output do you want \n1)not\n2)nor\n3)or\n4)and\n5)nand\nyour wanted output: ");
        scanf("%d", i);
        if (*i > 5 || *i < 1)
        {
            printf("You are dumb enter the output you want and this time do it properly\n");
            free(i);
            scanf("%d", i);
        }
        line();
        cases(*i);
        line();
    }
}
void entireTable()
{
    int *p;
    p = (int *)malloc(sizeof(int));
    printf("Which gate output do you want \n1)not\n2)nor\n3)or\n4)and\n5)nand\nyour wanted output: ");
    scanf("%d", p);
    line();
    if (*p > 5 || *p < 1)
    {
        printf("You are dumb enter the output you want and this time do it properly\n");
        printf("(last chance)Which gate output do you want \n1)not\n2)nor\n3)or\n4)and\n5)nand\nyour wanted output: ");
        free(p);
        scanf("%d", p);
    }
    if (*p == 1)
    {
        cases(1);
    }
    else
    {
        for (a = 0; a <= 1; a++)
        {
            for (b = 0; b <= 1; b++)
                cases(*p);
        }
    }
    line();
}

int main()
{
    int way;
    printf("Which way you want to get the table\n1) Entire table\n2) Inputs: \n");
    scanf("%d", &way);
    line();
    switch (way)
    {
    case 1:
        entireTable();
        break;
    case 2:
        withInput();
        break;

    default:
        printf("Run and READ the code again dummy!\n");
        break;
    }
}
