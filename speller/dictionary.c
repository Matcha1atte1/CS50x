// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word to obtain hash value
    unsigned int index = hash(word);

    // access linked list at that index in the hash table
    node *head = table[index];

    // traverse the linked list
    while(head != NULL)
    {
        if(strcasecmp(head->word, word) == 0)
        {
            return true;
        }
        head = head->next;
    }
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // check for correct word
    if(word == NULL || strlen(word) < 2)
    {
        return 0;
    }

    // get the first two letters
    char first = tolower(word[0]);
    char second = tolower(word[1]);

    // compute index using ascii
    unsigned int index = ((first - 'a')*26 + (second - 'a')) % N;

    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if(source == NULL)
    {
        printf("File could not be opened\n");
        return false;
    }

    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // read each word in the file
    char word[LENGTH];
    while(fscanf(source, "%s", word) == 1)
    {
         // add each word to the hash table
            node *n = malloc(sizeof(node));

            if(n == NULL)
            {
                return false;
            }

            strcpy(n->word, word);

            // call the hash function
            unsigned int index = hash(word);

            // insert node into hash table
            n->next = table[index];
            table[index] = n;
    }
    // close the dictionary file
    fclose(source);
    return true;

    // close the dictionary file
    else
    {
        return false;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    const char* dictionary;
    FILE *source = fopen(dictionary, "r");
    char word[LENGTH];
    unsigned int word_count = 0;
    while(fscanf(source, "%s", word) == 1)
    {
         // add each word to the hash table
            node *n = malloc(sizeof(node));

            strcpy(n->word, word);

            // call the hash function
            unsigned int index = hash(word);

            // insert node into hash table
            n->next = table[index];
            table[index] = n;
            word_count ++;
            return word_count;
    }
    fclose(source);
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // iterate through every bucket in the hash table
    for(int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while(cursor != 0)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        return true;
    }
    return false;
}
