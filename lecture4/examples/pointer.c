#include <stdio.h>

int main(void)
{
    int *x, valueint, y;
    valueint = 35;
    x = &valueint;
    y = *x;

    printf("O conteúdo de 'valueint' is: %i\n", valueint);
    printf("Endereço de 'valueint' is: %p\n", &valueint);
    printf("\n");

    printf("O conteúdo do ponteiro 'x' is: %p\n", x);
    printf("O endereço do ponteiro 'x' is: %p\n", &x);
    printf("O conteúdo da variável apontada por 'x' is: %i\n", *x);
    printf("\n");

    printf("O conteúdo de 'y' is: %i\n", y);
    printf("O endereço de 'y' is: %p\n", &y);
}
