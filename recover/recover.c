#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // accept a single command-line argument
    if(argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // open the memory card
    FILE *card = fopen(argv[1], "r");

    // check file was opened properly
    if(card == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }


}
