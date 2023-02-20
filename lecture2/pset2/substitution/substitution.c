#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool repeatedInString(string s);
bool check_string_composed_by_26_letters(string s);
int indx(char c);
void printFromIndex(string substKey, string text);

int main(int argc, string argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (check_string_composed_by_26_letters(argv[1]) == false)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else 
    {
        string cipherK = argv[1];
        string text = get_string("plaintext: ");

        printf("ciphertext: ");
        printFromIndex(cipherK, text);
    }
}

bool check_string_composed_by_26_letters(string s)
{
    bool result = true;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (n != 26)
        {
            return false;
        }
        if (isalpha(s[i]) == false)
        {
            return false;
        }
    }
    if (repeatedInString(s))
    {
        return false;
    }
    return result;
}

void printFromIndex(string substKey, string text)
{
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (islower(text[i]))
        {
            printf("%c", tolower(substKey[indx(text[i])]));
        }
        else if (isupper(text[i]))
        {
            printf("%c", toupper(substKey[indx(text[i])]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

int indx(char c)
{
    int i = 0;
    c = toupper(c);
    string alphab = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (c != alphab[i])
    {
        i++;
    }
    return i;
}

bool repeatedInString(string s)
{
    bool result = false;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        for (int j = 0, l = strlen(s); j < l; j++)
        {
            if (s[i] == s[j] && i != j)
            {
                result = true;
            }
        }

    }
    return result;
}