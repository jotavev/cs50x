#include <cs50.h>
#include <stdio.h>

bool isEven(int n);
int len(long n);
bool isValid(long n);
int digitSum(int n);

int main(void) 
{
    isValid(4003600000000014);
    printf("\ndigit sum 6: %i\n", digitSum(6));
    printf("\ndigit sum 9: %i\n", digitSum(9));
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
    int evenSum;
    int oddSum;
    int counter = 1;
    int lenght = len(n);
    int r;
    while (lenght > 0)
    {
        if (isEven(counter) == true)
        {
            if (lastNumber * 2 > 9)
            {
                r = (lastNumber * 2) % 10;
                r += ( lastNumber * 2 ) / 10;

                evenSum += r;
//                 printf("last number %i\n", lastNumber * 2);
//                 printf("\n\nr is: %i\n", r);
            }
            else
            {
                evenSum += (lastNumber * 2);
            }
            printf("%i", lastNumber);
        }
        else
        {
            
            oddSum += lastNumber;
        }
        n /= 10;
        lastNumber = n % 10;
        lenght--;
        counter++;

    }
    printf("\n");
    printf("\n%i\n", evenSum);
    printf("\nsum is: %i", evenSum + oddSum);

    return 0;
}


int digitSum(int n)
{
    int result;
    result = (n * 2) % 10;
    result += (n * 2) / 10;
    return result;
}
