#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user for positive integer
    int n;
    do
    {
        n = get_int ("Size: ");
    }
    while (n < 1);

    //print an n x n grid of blocks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
