#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Prompt the user for text
    string text = get_string("Text: ");

    //Count the number of letters, words and sentences in the text
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    //Compute the coleman-liau index
    float L = (letters/words)*100;
    float S = (sentences/words)*100;
    int index = round(0.0588*L - 0.296*S - 15.8);

    //Print the grade level
    if(index >= 16)
    {
        printf("Grade 16+\n");
    }

    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade%i\n", index);
    }
}

int count_letters(string text)
{
    //return the number of letters in the text
    int countl = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if(isalpha(text[i]))
        {
            countl++;
        }
    }
    return countl;
}

int count_words(string text)
{
    //return the number of words in the text
    //number of words = spaces + 1
    int countw = 1;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if(isspace(text[i]))
        {
            countw++;
        }
    }
    return countw;
}

int count_sentences(string text)
{
    //return the number of sentences in the text
    int counts = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if(text[i] == '.')
        {
            counts++;
        }
        if(text[i] == '!')
        {
            counts++;
        }
        if(text[i] == '?')
        {
            counts++;
        }
    }
    return counts;
}
