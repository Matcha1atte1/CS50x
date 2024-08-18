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

    // set jpeg counter
    int count = 0;

    // set currentfile
    FILE *currentfile = NULL;

    // allocate memory for filename
    char *filename = malloc(8);

    // while there is still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // check if it is a jpeg header (start of a jpeg)
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] && 0xf0) == 0xe0)
        {
            // create JPEGs from the data

            // check if it is the first jpeg found
            if(count == 0)
            {
                sprintf(filename, "%03i.jpg", 0);
                FILE *currentfile = fopen(filename, "w");
                count++;
            }
            // else if already found a jpeg
            else
            {
                fclose(currentfile);
                sprintf(filename, "%03i.jpg", count);
                FILE *currentfile = fopen(filename, "w");
                count++;
            }
        }
        if(currentfile != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, currentfile);
        }
    }

    free(filename);
    fclose(currentfile);
}
