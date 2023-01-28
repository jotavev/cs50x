#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (strcmp(s, t) == 0)
    {
        printf("same\n");
    }
    else 
    {
        printf("different\n");
    }
    printf("the address of s is: %p\n", s);
    printf("the address of t is: %p\n", t);
}
