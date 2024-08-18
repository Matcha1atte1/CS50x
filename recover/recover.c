#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // while there is still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // create JPEGs from the data
        
    }


}
