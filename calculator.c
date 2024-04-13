#include <stdio.h>
#include <cs50.h>

int add(int a, int b);

int main(void)
{
    //prompt user for x
    int x = get_int ("x: ");

    //prompt user for y
    int y = get_int ("y: ");

    //perform addition
    printf ("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b
}
