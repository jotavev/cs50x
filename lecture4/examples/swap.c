#include <cs50.h>
#include <stdio.h>

void swap(int a,int b);

int main(void)
{
    int x = 1;
    int y = 2;
    
    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    // precisava de trocar aqui e não funciona
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    printf("\na is %i, b is %i\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;

    //agora aqui dentro desse escopo o swap funciona
    printf("a is %i, b is %i\n\n", a, b);
}
