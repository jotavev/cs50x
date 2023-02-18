#include <stdio.h>
#include <cs50.h>

void printer(int size);
void printblank(int n);
void printhash(int n);

int main(void)
{
    int heigth;
    do
    {
        heigth = get_int("Heigth: ");
    }
    while (heigth < 1 || heigth > 8);

    printer(heigth);
}

void printer(int size)
{
    int printBlankTimes = size;
    int printHashTimes = 1;
    for (int i = 0; i < size; i++)
    {
        printBlankTimes--;
        printblank(printBlankTimes);
        printhash(printHashTimes);
        printf("  ");
        printHashTimes++;


        printf("\n");
    }
}

void printblank(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void printhash(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}
