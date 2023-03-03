# Data Structures

## Arrays 

no fim das contas tudo que tem dentro da memoria são apenas bytes, 0's e 1's, e tudo depende de como iremos usar esse bytes, como interconectalos, como representar informações (data) usando eles, e, arrays são a forma mais simples de começarmos a "brincar" e entender como isso tudo funciona, pois arrays são um pedaço contínuo de memória, um atrás do outro. 

## Problemas com arrays

Porém, problemas surgem rapidamente com arrays.

Imaginemos que temos um pedaço de memória com 3 bites:

```
|---|---|---|
| 1 | 2 | 3 |
|---|---|---|
```

e precisamos armazenar, agora, também o número 4 como isso seria possível?

```
|---|---|---|---|
| 1 | 2 | 3 | ^ |
|---|---|---|---|
```
poderiamos adicionar o 4 imediatamente após o 3, porém no contexto da memória do computador pode haver outras coisas por lá

```
|---|---|---|---|---|---|---|---|
| $ | $ | $ | $ | $ | $ | $ | $ |
|---|---|---|---|---|---|---|---|
| $ | 1 | 2 | 3 | h | e | l | l |
|---|---|---|---|---|---|---|---|
| l | , |   | w | o | r | l | d |
|---|---|---|---|---|---|---|---|
|\0 | $ | $ | $ | $ | $ | $ | $ |
|---|---|---|---|---|---|---|---|
```
, alguns dessas coisas podem ser valor de lixo (garbage value) que nesse caso são representados por `$`, valores que não tem importacia para o programa, ou até mesmo valores importantes como no exemplo acima, supondo que você criou o array `123` e usou `get_string` na linha seguinte, ou apenas criou uma string `hello, world`, então basicamente o `123` está encurralado agora.

Então onde exatamente adicionariamos o 4?

Uma das soluções é duplicar o array `123` para outro espaço da memória e adicinar o `4` no fim dele.

Um problema para essa solução seria o incremento no tempo de execução.

Tudo bem que o array desse exemplo é pequeno, mas se tivermos usando os dados de um aplicativo web, ou aplicativo molibe, onde não tem só 3 dados, mas talvez algumas centenas, milhares ou milhões de dados. 

Então para solucionar esse problema precisaremos aprender uma nova parte da sintaxe: `Arrow Notation`

## Arrow Notation

arrow sintaxe se baseia em 3 coisas já aprendidas anteriormente no curso:

* `Struct` permite criar uma estrutura, com varios tipos de dados
* `.` acessa um campo de uma estrutura
* `*` acessa um endereço de memoria (derreferencia), cria um ponteiro
 
uma abreviação de `.` e `*` é `->`

## Linked Lists

listas linkadas é uma das soluções para o problema dado anteriormente
por exemplo, temos 3 números em pedaços distintos da memória

```
|-------|-------|-------|-------|-------|
|   1   |       |       |       |       |
| 0x123 |       |       |       |       |
|-------|-------|-------|-------|-------|
|       |       |   2   |       |       |
|       |       | 0x456 |       |       |
|-------|-------|-------|-------|-------|
|       |       |       |       |   3   |
|       |       |       |       | 0x789 |
|-------|-------|-------|-------|-------|
|       |       |       |       |       |
|       |       |       |       |       |
|-------|-------|-------|-------|-------|
```

e precisamos que um leve ao outro, então pode-se armazenar ao lado dos números, o endereço do próximo número

```
|-------|
|   1   |
| 0x123 |
|-------|       |-------|
| 0x456 | ----> |   2   |
|       |       | 0x456 |
|-------|       |-------|       |-------|
                | 0x789 | ----> |   3   |
                |       |       | 0x789 |
                |-------|       |-------|
                                |  0x0  |
                                |       |
                                |-------|
```
e por ultimo usar o endereço reservado `0x0`.

```
|-------|
|   1   |
|       |
|-------|       |-------|
|    ---|-----> |   2   |
|       |       |       |
|-------|       |-------|       |-------|
                |   ----|-----> |   3   |
                |       |       |       |
                |-------|       |-------|
                                |       |
                                |       |
                                |-------|
```
Então no fim do dia a representação seria essa, tendo em vista que o endereço especifico da memória não nos importa tanto, mas sim como o código funciona e como ele pode ser util. 

Com isso temos um aumento na memória necessária para armazenas os dados, pois temos que armazenar os ponteiros também, porém ganhamos com a flexibilidade de não precisar achar um pedaço de memória contínua e ficar realocando toda vez que houver uma nova inclusão de um dado.

Há sempre um tradeoff. Nesse caso é sacrificado um espaço de memória para melhorar o tempo de execução.

qual seria o código em C para isso?

uma estrutura já criada no curso foi a `person`:
```
typedef struct
{
    sting name;
    string number;
}
person;
```

reutilizando-a para abstrair essa nova, pode-se fazer::
```
typedef struct
{
    int number; // o primeiro dado do tipo int para armazenar o número
    node *next; // o segundo dado do tipo node (nó) para armazenar o endereço do próximo
}
node;
```

porém o código é lido de cima para baixo, o compilador irá chegar na 4ª linha do código e não saberá o que diabo é o tipo node, pois ele ainda não foi declarado, somente na 6ª linha acontece sua declaração

para solucionar esse problema, podemos fazer:

```
typedef struct node // agora o compilador vai saber o que é node
{
    int number;
    struct node *next;
}
node;
```

para declarar uma lista node, podemos fazer:
```
node *list = NULL; 

//atribuimos o NULL para que a lista não fique com um valor lixo.
```

para adicionar algo nessa lista encadeada:
```
node *n = malloc(sizeof(node)); 

//usando malloc para conseguir espaço suficiente para um node.
```

para inserir apenas o número 1:
```
if (n != NULL)
{
    (*n).number = 1;
}
```
usando o `*` como operador de derreferencia, para ir para o n, e o `.` para acessar o campo number

porém como dito anteriormente em `Arrow Notation`, podemos substituir e usar uma sintaxe mais descomplicada e de fácil leitura:

```
if (n != NULL)
{
    n->number = 1;
}
```

e agora podemos atribuir o valor de next:

```
if (n != NULL)
{
    n->next = NULL;
}
```

então podemos fazer com que a `list` que declaramos no inicio aponte para o que criamos e está sendo apontado por `n` (`n` aqui funciona como um `tmp`).

```
list = n;
```

então, antes de fazemos isso, o `n` está apontado para nosso node, e `list` está com valor `NULL`, após esse comando `list` passa a apontar para onde `n` aponta.

a complexidade de listas encadeadas é `O(n)` e o omega é `omega(1)` e o insert dela pode ser `O(1)`

## trees 

