#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int height, row, column, space;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (row = 0; row <= height - 1; row++)
    {
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
