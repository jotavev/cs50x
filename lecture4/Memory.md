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

## Char

## Pointer Arithmetic 

## malloc and free 

## valgrid

