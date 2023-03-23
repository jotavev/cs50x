// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// const unsigned int N = 26;
#define N 2600

int sum = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int h = hash(word);
    for (node *tmp = table[h]; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // polynomial accumulation using horner's rule 
    int h = word[0];
    for (int i = 1; word[i] != '\0'; i++)
    {
        h += h * 33 + word[i];
    }
    return h % N;
    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            free(n);
            return false;
        }

        int h = hash(word);

        strcpy(n->word, word);
        n->next = table[h];
        table[h] = n;
        sum++;
    }
    return true;
    // TODO
    // return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sum;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
