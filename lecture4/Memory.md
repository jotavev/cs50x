## Pixel 

uma imagem digital é uma matriz 

cada elemento da matriz em uma imagem é denominado pixel (picture element)

cada pixel descreve, de alguma forma apropriada, uma cor para aquele ponto da imagem

como uma imagem é armazenada com um número finito de bytes, cada um (talvez) representando um valor vermelho, verde ou azul para cada pixel

## Hexadecimal

extremamente comum para representar as cores rgb, o hexadecimal ou base-16 é uma forma diferente de representar dados:

0 1 2 3 4 5 6 7 8 9 A B C D E F

onde os digitos de 0 a 9 representam a si mesmos e A ao F representam de 10 a 15

ele foi criado pois é mais fácil de ler (comparado com binário) além de ser mais fácil converter hex to bin do que dec to bin

leitura recomendada: Code: the hidden language of computer hardware and software

## Memory Address

outra utilização muito comum do hex é descrever o endereço de memoria 

0x0  0x1  0x2  0x3  0x4  0x5  0x6  0x7 

0x8  0x9  0xA  0xB  0xC  0xD  0xE  0xF

0x10 0x11 0x12 0x13 0x14 0x15 0x16 0x17

0x18 0x19 0x1A 0x1B 0x1C 0x1D 0x1E 0x1F ...

## Pointers

Um ponteiro é uma variavel especial que contém um endereço na memória armazenado, em vez de dados comuns. Esse endereço é, no geral, a posição na memória de outra variável. Desta forma, a variavel que contém esse endereço aponta para a outra variável. E por isso o nome "ponteiro".

ou seja ponteiro é uma variável com um endereço que aponta para outra variável.
(só pra lembrar que variável é um pedaço de memoria que guarda algum dado)

Ponteiros são muito importantes em C, especialmente para criar filas e lista encadeadas entre outras estruturas de dados.

## Declarar Ponteiro

datatype *varName;

o * (star) é o 

## Dereference Operator 

## Strings 

nas primeiras semanas do cs50, o tipo de dado string foi amplamente usado, advindo da cs50.h

por exemplo a string

    string s = "HI!";

que basicamente armazena 'HI!\0' na variavel s

onde o:

s[0] = 'H'
s[1] = 'I'
s[2] = '!'
s[3] = '\0'

(o \0 é a forma de informar ao computador que é o fim da string)

se hipoteticamente os endereços de memoria dessa string forem

0x123 = 'H'
0x124 = 'I'
0x125 = '!'
0x126 = '\0'

então se o computador está alocando esses chars na memória o que exatamente é a variavel s?
(obviamente s é um tipo de dado criado pela cs50.h, porém por baixo do capô, oq é s?)

s é um ponteiro, que aponta expecificamente para o endereço de memória da primeira letra da string

 'H'     'I'     '!'     '\0'
0x123   0x124   0x125   0x126
  ^
  |
  s

no exemplo acima vemos o s apontar para o enderço, ok?

s aponta para o inicio e \0 indica que é o final

se s é um ponteiro, para um char (o primeiro da string), então s é:

char *s = "HI!";

## Datatype string

typedef char *string;

## Pointer Arithmetic 

int main(void) 
{
    char *s = "HI!";
    char *s = ("%c\n", *s);  <- aqui vai printar o s e no caso o s é endereço do primeiro char
    char *s = ("%c\n", *(s + 1));  <- aqui vai printar endereço do s + 1 | se o endereço for 0x123 então s + 1 = 0x124
    char *s = ("%c\n", *(s + 2));  <- e assim por diante
    char *s = ("%c\n", *(s + 3));  <- aqui por ex vai printar o \0 que indica o fim da string
}

então podemos executar aritmetica com os ponteiro e seus endereços

exatamente como já faziamos com 's[0]'

e tudo isso ai de cima também vale para arrays (falavamos de arrays de char, porém), vale também para array de int float e assim por diante, todos são ponteiros apontando para o primeiro elemento do array.

## malloc and free 

## valgrid

