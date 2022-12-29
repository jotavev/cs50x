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
//     printf("n: 378282246310005");
//     position(378282246310005, 1);
//     position(378282246310005, 2);
//     printf("n:3566002020360505");
//     position(3566002020360505, 1);
//     position(3566002020360505, 2);
//     printf("n: 4222222222222");
//     position(4222222222222, 1);
//     position(4222222222222, 2);
    long creditNumber;
    do
    {
        creditNumber = get_long("Number: ");
    }
    while (creditNumber < 1);
    if (isValid(creditNumber) == true)
    {
        checkFlagCard(creditNumber);
    }
    else
    {
        printf("IVALID\n");
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
    } while (n);
    return lenght;
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
//             printf("%i", lastNumber);
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
    if ((evenSum + oddSum) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    else if ((position1 == 5) && (position2 > 0 || position2 < 6))
    {
        printf("MASTERCARD\n");
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
//     printf("\nthe position %i of number is %i\n", digitPosition, result);
    return result;
}
