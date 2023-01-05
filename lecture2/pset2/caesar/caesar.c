#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
        printf("plaintext: \n");
    }
//     printf("%i", cipherN);

    printf("test1 = EXPECTED: 0 | RECIEVED: %i\n", check_string_composed_by_digits("abc"));
    printf("test2 = EXPECTED: 0 | RECIEVED: %i\n", check_string_composed_by_digits("hjk"));
    printf("test1 = EXPECTED: 1 | RECIEVED: %i\n", check_string_composed_by_digits("123"));
    printf("test1 = EXPECTED: 1 | RECIEVED: %i\n", check_string_composed_by_digits("22"));
    printf("test1 = EXPECTED: 0 | RECIEVED: %i\n", check_string_composed_by_digits("2a2"));
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
