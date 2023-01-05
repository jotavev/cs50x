#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char charshiter(char c, int n);
void printshift(string s, int n);
bool check_string_composed_by_26_letters(string s);
int indx(char c);

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
        printf("%i\n", indx('A'));
        printf("%i\n", indx('C'));
        printf("%i\n", indx('B'));
        printf("%i\n", indx('D'));
        printf("%i\n", indx('Z'));
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

void printshift(string s, int n)
{
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        printf("%c", charshiter(s[i], n));
    }
    printf("\n");

}

// string arr = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
// string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string dic = "HELLO";

int indx(char c)
{
    int i = 0;
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (c != alp[i])
    {
        i++;
    }
    return i;
}

char charshiter(char c, int n)
{
    int shifted = c + n;
    if (isalpha(c))
    {
        while (isalpha(shifted) == false)
        {
            shifted -= 26;
        }
        return shifted;
    }
    else
    {
        return c;
    }
}
