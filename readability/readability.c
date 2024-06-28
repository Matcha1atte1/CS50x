#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letters(string text);

int main(void)
{
    //Prompt the user for text
    string text = get_string("Text: ");

    //Count the number of letters, words and sentences in the text

    //Compute the coleman-liau index

    //Print the grade level

}

int count_letters(string text)
{
    //return the number of letters in the text
    int count = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if(isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    
}
