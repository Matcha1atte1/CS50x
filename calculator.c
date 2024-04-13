#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //prompt user for x
    int x = get_int ("x: ");

    //prompt user for y
    int y = get_int ("y: ");

    //perform addition
    printf ("%i\n", x + y);
}
