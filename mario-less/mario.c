#include <cs50.h>
#include <stdio.h>

int main (void)
{
    //prompt user for positive integer
    int n;
    do {
        n = get_int("Height: ");
    }
    while (n < 1);

    //print n height pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
