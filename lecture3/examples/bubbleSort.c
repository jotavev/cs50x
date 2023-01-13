#include <stdio.h>

int main(void)
{
    int numbers[] = {5, 2, 1, 3, 6, 4};

    int len = 6;

    int aux;
    
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < (len - i - 1); j++)
        {
            if(numbers[j] > numbers[j + 1])
            {
                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }

    printf("%i ", numbers[0]);
    printf("%i ", numbers[1]);
    printf("%i ", numbers[2]);
    printf("%i ", numbers[3]);
    printf("%i\n", numbers[4]);
}
