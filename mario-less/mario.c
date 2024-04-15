#include <cs50.h>
#include <stdio.h>

int main (void)
{
    //prompt user for positive integer
    int height, row;
    do {
        height = get_int("Height: ");
    }
    while (height < 1);

    //print pyramid of n height
    for (row = 0; row < n; row++)
    {
        for (column = 0; j < n; j++)
        {
            if (i + j < n - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
