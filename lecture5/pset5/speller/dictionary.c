// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
//#define N 2600
const unsigned int N = 2600;

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
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // polynomial accumulation using horner's rule

    char lower[LENGTH + 1];
    unsigned int h = 0;
    int j = 0;

    for (j = 0; word[j] != '\0'; j++)
    {
        lower[j] = tolower(word[j]);
    }
    lower[j] = '\0';

    for (int i = 0; lower[i] != '\0'; i++)
    {
        h += h * 33 + lower[i];
    }

    return h % N;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file)
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
    fclose(file);
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
    for (int i = 0; i <= N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    for (int i = 0; i <= N; i++)
    {
        if (table[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
