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
        int count = 0;
        // check if it is a jpeg header
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] && 0xf0) == 0xe0)
        {
            count++;
            // check if it is the first jpeg found
            if(count == 1)
            {
                char *output = malloc(8);
                sprintf(output, "%03i.jpg", 0);
                
            }

            // else if already found a jpeg
        }
        // create JPEGs from the data

    }


}
