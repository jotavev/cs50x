# Defining Custom Types

`struct` é usado para definir um novo tipo de dado composto, chamado de estrutura, ou seja, podemos criar uma coleção de variáveis de diferentes tipos agrupadas sob um único nome.

```
struct pessoa 
{
    char *nome;
    int idade;
    float altura;
}
```

`typedef` é usado para atribuir um nome novo para um tipo de dado já existente. Tornando assim o código mais curto e legivel.
como por exemplo `string` usada no cs50.h

```
typedef char* string;
```

então `typedef` tem a sintaxe:

```
typedef <old name> <new name>;
``` 

exemplo de typedef:

```
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};

typedef struct car car_t;
```

então seguindo oq sabemos até agora:

```
typedef struct car car_t;
        ^      ^   ^  
        old name   new name
```

como o typedef é muito comum de ser usado após structs, existe outro jeito comum de fazer o mesmo que fizemos acima que é:


```
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
}
car_t;
```

então como mencionado anteriormente typedef serve para encurtar, e tornar mais legivel, um exemplo prático é se usarmos o codigo acima, sem typedef, a declaração da variavel seria:

```
struct car mycar;
```

agora com typedef a declaração da variavel ficar assim:

```
car_t mycar;
```

só com o tipo e o nome da variavel, mais legivel e mais curto, exatamente como a proposta.
