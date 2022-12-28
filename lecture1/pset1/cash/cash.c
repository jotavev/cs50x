#include <cs50.h>
#include <stdio.h>

int calc(int n, int m)
{
    int counter = 0;
    while (n >= m)
    {
        n -= m;
        counter++;
    }
    return counter;
}

int calculate_quarters(int n)
{
    int result = calc(n, 25);
    return result;
}

int calculate_dimes(int n)
{
    int result = calc(n, 10);
    return result;
}

int calculate_nickels(int n)
{
    int result = calc(n, 5);
    return result;
}

int calculate_pennies(int n)
{
    int result = calc(n, 1);
    return result;
}

int main(void)
{
    int get_cents;
    do
    {
        get_cents = get_int("Change owed: ");

    }
    while (get_cents < 1);

    int cents = get_cents;

    int quarter = calculate_quarters(cents);

    printf("quarter is %i\n", quarter);
    printf("cents is %i\n", cents);
    cents = cents - (25 * quarter);

    int dimes = calculate_dimes(cents);

    printf("cents after calc %i\n", cents);
    cents = cents - (10 * dimes);

    int nickels = calculate_nickels(cents);
    
    cents = cents - (5 * nickels);

    int pennies = calculate_pennies(cents);

    int sum = quarter + dimes + nickels + pennies;

    printf("troquinho é %i\n", sum);
}
