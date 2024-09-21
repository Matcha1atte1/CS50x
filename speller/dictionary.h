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
        return false;
    }

    // read each word in the file
    while(fscanf(file, "%s", word) == 1)
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

            n->next = 

    }



    // close the dictionary file
    fclose(source);
}
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
