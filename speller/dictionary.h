// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word);
{
    // hash word to obtain hash value
    unsigned int index = hash(word);

    // access linked list at that index in the hash table
    node *head = hashtable->table[index];

    // traverse the linked list 

}
unsigned int hash(const char *word);
{
    // check for correct word
    if(word == NULL || strlen(word) < 2)
    {
        return 0;
    }
    // set bucket size
    int N = 50;
    // get the first two letters
    char first = tolower(word[0]);
    char second = tolower(word[1]);

    // compute index using ascii
    unsigned int index = ((first - 'a')*26 + (second - 'a')) % N;

    return index;
}
bool load(const char *dictionary);
{
    // open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if(source == NULL)
    {
        printf("File could not be opened\n");
        return false;
    }

    for(int i = 0; i < N; i++)
    {
        hashtable->table[i] = NULL;
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
            n->next = hashtable->table[index];
            hashtable->table[index] = n;
    }

    // close the dictionary file
    fclose(source);

    return true;
}
unsigned int size(void);
{
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
            n->next = hashtable->table[index];
            hashtable->table[index] = n;
            word_count ++;
    }
    fclose(source);
    return word_count;
}
bool unload(void);

#endif // DICTIONARY_H
