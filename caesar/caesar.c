#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    // Make sure every character in argv[1] is a digit

    if(only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a string to an int
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // For each character in the plaintext:
    for(int i = 0, length = strlen(plaintext); i < length; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    // Rotate the character if it is a letter
}

bool only_digits(string s)
{
    for(int i = 0, length = strlen(s); i < length; i++)
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
            char shifted_charupper = ((c - 65) + n ) % 26) + 'A';
        }
        if(islower(c))
        {
            char shifted_charlower = ((c - 97) + n) % 26) + 'a';
        }
    }
 }
}
