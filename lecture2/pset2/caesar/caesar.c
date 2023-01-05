#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char charshiter(char c, int n);
void printshift(string s, int n);
bool check_string_composed_by_digits(string s);

int main(int argc, string argv[]) 
{
    int cipherN = atoi(argv[1]);
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (check_string_composed_by_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else 
    {
        string text = get_string("plaintext: ");
        printshift(text, cipherN);

    }
//     printf("%c\n", charshiter('a', 1));
//     printf("%c\n", charshiter('Z', 1));
//     printf("%c\n", charshiter(',', 1));
//     printf("%c\n", charshiter(' ', 1));
}

bool check_string_composed_by_digits(string s)
{
    bool result = true;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == false)
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

char charshiter(char c, int n)
{
    int shifted = c + n;
    if (isalpha(c))
    {
        if (isalpha(shifted) == false)
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
