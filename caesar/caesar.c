#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    // Make sure every character is argv[1] is a digit

    // Convert argv[1] from a string to an int

    // Prompt user for plaintext

    // For each character in the plaintext:

    // Rotate the character if it is a letter
}

bool only_digits(string s)
{
    for(int i = 0; length = strlen(s); i < length; i++)
    {
        if(isdigit(s))
        {
            return true;
        }
    }
}
