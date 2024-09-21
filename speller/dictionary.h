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

    if(source == NULL)
    {
        printf("File could not be opened\n");
        return 1;
    }

    // read each word in the file
    for()
    fscanf(file, "%s", word)


    // add each word to the hash table
    node *n = malloc(sizeof(node));

    // close the dictionary file
    fclose(source);
}
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
