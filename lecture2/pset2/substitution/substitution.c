#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

        printf("\n\n\n");
        printf("the index of 'A' is: %i\n", indx('a'));
        printf("the index of 'C' is: %i\n", indx('C'));
        printf("the index of 'B' is: %i\n", indx('B'));
        printf("the index of 'D' is: %i\n", indx('D'));
        printf("the index of 'Z' is: %i\n", indx('Z'));
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
    return result;
}

void printFromIndex(string substKey, string text)
{
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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

// string arr = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
// string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string dic = "HELLO";

//i need to the inversal logic in this function
//ao inves de pegar o index do caractere do texto e usar ele pra printar
//a susbtKey[index] eu tenho que pegar o 
int indx(char c)
{
    int i = 0;
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    if (isupper(c))
    {
        while (c != upper[i])
        {
            i++;
        }
        return i;
    }
    else if (islower(c))
    {
        while (c != lower[i])
        {
            i++;
        }
        return i;
    }
    else
    {
        return i;
    }
}

// void printshift(string s, int n)
// {
//     for (int i = 0, j = strlen(s); i < j; i++)
//     {
//         printf("%c", charshiter(s[i], n));
//     }
//     printf("\n");
// 
// }
