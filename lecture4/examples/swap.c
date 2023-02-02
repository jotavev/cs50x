#include <stdio.h>

void swap(int *a,int *b);

int main(void)
{
    int x = 1;
    int y = 2;
    
    printf("x is %i, y is %i\n", x, y);
    printf("x ad %p y ad %p\n", &x, &y);
    swap(&x, &y);
    // precisava de trocar aqui e não funciona
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    printf("0. a is %p b is %p\n", &a, &b);
    printf("1. a is %i b is %i\n", *a, *b);
    int tmp = *a;
    printf("2. a is %i b is %i\n", *a, *b);
    *a = *b;
    printf("3. a is %i b is %i\n", *a, *b);
    *b = tmp;
    printf("4. a is %i b is %i\n", *a, *b);
}
