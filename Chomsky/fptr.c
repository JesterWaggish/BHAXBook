#include <stdio.h>

int
sum (int a, int b)
{
    return a + b;
}

int
mul (int a, int b)
{
    return a * b;
}

int (*sumormul (int c)) (int a, int b)
{
    if (c)
        return mul;
    else
        return sum;

}

int
main ()
{
    // Feladat eleje

    int a;
    int *b = &a;
    int &r = a;         //g++
    int c[5];
    int (&tr)[5] = c;   //g++
    int *d[5];
    int *h();
    int *(*l)();

    // Függvénypointerek

    int (*f) (int, int);

    f = sum;

    printf ("%d\n", f (2, 3));

    int (*(*g) (int)) (int, int);

    g = sumormul;

    f = *g (42);

    printf ("%d\n", f (2, 3));

    return 0;
}
