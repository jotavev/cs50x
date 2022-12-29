#include <cs50.h>
#include <stdio.h>

bool isEven(int n);
int len(long n);
bool isValid(long n);

int main(void) 
{
    isValid(4003600000000014);
    long creditNumber;
    do
    {
        creditNumber = get_long("Number: ");
    }
    while (creditNumber < 1);
    printf("len is: %i", len(creditNumber));
}

bool isEven(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int len(long n)
{
    int lenght = 0;
    do
    {
        lenght++;
        n /= 10;
    } while (n);
    return lenght;
}

bool isValid(long n)
{
    int lastNumber = n % 10;
    int result;
    int counter = 1;
    int i = len(n);
    int r;
    while (i > 0)
    {
        if (isEven(counter) == true)
        {
            if (lastNumber * 2 > 9)
            {
                r = (lastNumber * 2) % 10;
                r += ( lastNumber * 2 ) / 10;


                result += r;
                printf("last number %i\n", lastNumber * 2);
                printf("\n\nr is: %i\n", r);
            }
            else
            {
                result += (lastNumber * 2);
            }
            printf("%i", lastNumber);
        }
        n /= 10;
        lastNumber = n % 10;
        i--;
        counter++;

    }
    printf("\n");
    printf("\n%i\n", result);

    return 0;
}


