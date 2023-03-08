# Structs

* Estruturas nos possibilita um jeito para unir varios tipos diferentes de dados em um só, um novo tipo customizado que pode receber seu proprio nome

* Usamos estruturas para agrupar elementos de varios tipos de dados que possuem uma conexão lógica

* Pense em uma estrutura como uma "super variável"

```
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
}


// variable declaration
struct car mycar;

// field acessing 
mycar.year = 2011;
strcpy(mycar.plate, "CS50");
mycar.odometer = 50505;
```

* Estruturas, assim como variaveis ou todos os outros tipos de dados, não precisam serem criados necessariamente na stack. Podemos alocar estruturas dinamicamente no tempo de execução se o programa exigir isso.

* Nessa situação o operador ponto não é suficiente, precisamos usar o operador de derreferencia para apontar para a estrutura primeiro e depois acessamos o campo.

```
// variable declaration 
struct car *mycar = malloc(sizeof(struct car));

// fields acessing 
(*mycar).year = 2011;
strcpy((*mycar).plate = "CS50");
(*mycar).odometer = 50505;
```

* Existe uma forma mais descomplicada e visualmente limpa de se fazer isso.

* O operador de seta (->) faz isso se tornar mais fácil unindo dois passos em um:

** Primeiro, ele *derrefencia* o ponteiro do lado esquerdo do operador
** Segundo, ele *acessa* o campo que está no lado direito do operador

```
// variable declaration 
struct car *mycar = malloc(sizeof(struct car));

// fields acessing 
mycar->year = 2011;
strcpy(mycar->plate = "CS50");
mycar->odometer = 50505;
```
