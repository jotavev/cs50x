#include <cs50.h>
#include <stdio.h>
#include <string.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");

    int length = strlen(name);

    printf("the length of name is: %i\n", length);
}

