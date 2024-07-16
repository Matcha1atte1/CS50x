#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdiolib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character is argv[1] is a digit

    if only_digits(argv[1]) == false
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a string to an int
    int number = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

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
        else
        {
            return false;
        }
    }
}

char rotate(char c, int n)
{
    if(isalpha(c))
    {
        if(isupper(c))
        {
            
        }
    }

    }
}
