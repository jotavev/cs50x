#include <cs50.h>
#include <stdio.h>

bool isEven(int n);
int len(long n);
bool isValid(long n);
int digitSum(int n);
void checkFlagCard(long creditCardNumber);
int position(long n, int digitPosition);

int main(void) 
{

    long creditNumber;
    do
    {
        creditNumber = get_long("Number: ");
    }
    while (creditNumber < 1);

    int i;

    i = isValid(creditNumber);

    if (i  == false || len(creditNumber) < 11)
    {
        printf("INVALID\n");
    }
    else 
    {
        checkFlagCard(creditNumber);
    } 
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
    }
    while (n);
    return lenght;
}



int digitSum(int n)
{
    int result;
    result = (n * 2) % 10;
    result += (n * 2) / 10;
    return result;
}

void checkFlagCard(long creditCardNumber)
{
    int position1 = position(creditCardNumber, 1);
    int position2 = position(creditCardNumber, 2);

    if (position1 == 4)
    {
        printf("VISA\n");
    }
    else if ((position1 == 3) && (position2 == 4 || position2 == 7))
    {
        printf("AMEX\n");
    }
    else if ((position1 == 5) && (position2 > 0 && position2 < 6))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

int position(long n, int digitPosition)
{
    int lenght = len(n);
    int result;
    while (lenght > 0)
    {
        if (lenght == digitPosition)
        {
            result = n % 10;
        }

        n /= 10;
        lenght--;
    }
    return result;
}

bool isValid(long creditCardNumber)
{
    int lastNumber = creditCardNumber % 10;
    int evenSum;
    int oddSum;
    int counter = 1;
    int lenght = len(creditCardNumber);

    // while works with the lenght of credit card number
    while (lenght > 0)
    {
        // if the counter is even part of luhn's algorithm 
        // are applied (for even numbers)
        if (isEven(counter) == true)
        {
            // if number * 2 is higher than 9 digits of number
            // are addeds according luhn's algorithm
            if (lastNumber * 2 > 9)
            {
                evenSum += digitSum(lastNumber);
            }

            else
            {
                evenSum += (lastNumber * 2);
            }
        }

        //if the counter is odd, the other part of luhn's algorithm are applied
        else
        {
            oddSum += lastNumber;
        }

        // remove the last number of credit card
        creditCardNumber /= 10;

        // pick the new last number of credit card
        lastNumber = creditCardNumber % 10;

        lenght--;
        counter++;
    }

    //check the total modulo 10 is congruent to 0
    int total = 1;
    total = (evenSum + oddSum) % 10;
    if (total == 0)
    {
        return true;
    }
    if (total > 0)
    {
        return false;
    }
    else
    {
        return false;
    }
}
