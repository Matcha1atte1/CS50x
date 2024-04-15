#include <cs50.h>
#include <stdio.h>

int main (void)
{
    //prompt user for positive integer
    int height, row, column, space;
    do {
        height = get_int("Height: ");
    }
    while (height < 1);

    //print pyramid of inputted height
    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1)
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
