#include <stdio.h>

void meow(int times);

int main(void)
{
   meow(6);
}

   

void meow(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("meow\n");
    }
}

/* int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
    
} */

