#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    //printf the chars
    printf("%c", s[0]);
    printf("%c", s[1]);
    printf("%c", s[2]);
    printf("%c", s[3]);

    printf("\n\n\n");

    //print the chars with pointer arithmetic
    printf("%c", *s);
    printf("%c", *(s + 1));
    printf("%c", *(s + 2));
    printf("%c", *(s + 3));
    printf("\n");
}
