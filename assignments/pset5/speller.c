// Implements a dictionary's functionality
 // this code will not complile outside of CS50 IDE needs other files


#include <strings.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 35; 

// Hash table 
node *table[N] = {NULL};

// Declare a counter 
unsigned int wordcount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Obtain hash index
    unsigned int hashindex = hash(word);
    // Create traversal pointer 
    node *trav = table[hashindex];
    // Search until null pointer
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
      
        trav = trav->next;
    }
    return false;
}

unsigned int hash(const char *word)
{
    // Convert to lowercase
    int len = strlen(word);
    char wordarr[len + 1];
    strcpy(wordarr, word);
    for (int i = 0; wordarr[i]; i++)
    {
        wordarr[i] = tolower(wordarr[i]);
    }

    unsigned long hash = 5381;
    int c = 0;

    for (int i = 0; c == wordarr[i]; i++)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N; 
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary 
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }

    // array to store each word scanned
    char getword[LENGTH + 1];

   
    while (fscanf(fp, "%s", getword) != EOF)
    {
        // Allocate memory 
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // Assign values into the node using hash
        unsigned int hashindex = hash(getword);
        strcpy(n->word, getword);
        n->next = table[hashindex]; 
        table[hashindex] = n;

        // Increase wordcount
        wordcount++;
    }
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    
    for (int i = 0; i < N; ++i)
    {
        // Create pointers
        node *freeptr = table[i];
        node *cursor = table[i];
        //  Free each node
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(freeptr);
            freeptr = cursor;
        }
    }
    return true;
}