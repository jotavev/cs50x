#include <stdio.h>

int main(void)
{
    int numbers[] = {5, 2, 1, 3, 6, 4};

    int aux;
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if(numbers[i] > numbers[j])
            {
                aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
        }
    }

    printf("%i ", numbers[0]);
    printf("%i ", numbers[1]);
    printf("%i ", numbers[2]);
    printf("%i ", numbers[3]);
    printf("%i\n", numbers[4]);
}
