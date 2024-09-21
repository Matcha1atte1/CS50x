// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
{
    // open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if(fopen == NULL)

    // read each word in the file


    // add each word to the hash table

    // close the dictionary file
}
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
