#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // criando uma string s 
    string s = "HI!";
    // criando um ponteiro que aponta para o endereço de s[0] 
    char *p = &s[0];
    // printando o endereço de s
    printf("%p\n", s);
    // printando o p (lembrando que p é o ponteiro da primeira letra de s)
    printf("%p\n", p);
}
