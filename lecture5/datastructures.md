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

## binary search trees 

pode-se criar uma estrutura de dados chamada arvore, semelhante a uma arvore genealogica.

podemos usar uma lista com 7 elementos de exemplo 

```
|---|---|---|---|---|---|---|
| 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|
```

ela ficaria assim:


```
            |---|            
            | 4 |            
        ____|---|____            
       /             \
      v               v
    |---|           |---|    
    | 2 |           | 6 |    
    |---|           |---|    
   /     \         /     \
  v       v       v       v
|---|   |---|   |---|   |---|
| 1 |   | 3 |   | 5 |   | 7 |
|---|   |---|   |---|   |---|
```

onde basicamente funcionaria como o exemplo de achar um nome em uma lista telefônica, porém agora com uma arvore e não um array.

o código é algo como:
```
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;
```

e para pesquisar algo usando binary tree seria assim:

```
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else
    {
        return true;
    }
}
```
a complexidade de busca é `O(log n)` e de inserção é `O(log n)`

## Hash tables

Hash table é um canivete suiço das estruturas de dados, e é amplamente utilizado. ela permite associar chaves com valores.

```
 0 -> |¯|
 1 -> |¯|
 2 -> |¯|
 3 -> |¯|
 4 -> |¯|
 5 -> |¯|
 6 -> |¯|
 7 -> |¯|
 8 -> |¯|
 9 -> |¯|
10 -> |¯|
11 -> |¯|
12 -> |¯|
13 -> |¯|
14 -> |¯|
15 -> |¯|
16 -> |¯|
17 -> |¯|
18 -> |¯|
19 -> |¯|
20 -> |¯|
21 -> |¯|
22 -> |¯|
23 -> |¯|
24 -> |¯|
25 -> |¯|
       ¯
```

podemos pensar que cada local está rotulado com uma letra de A a Z e inserir nomes:

```
|-|--->|Albus    |  |
|-|--->|         |  |
|-|--->|Cedric   |  |
|-|--->|Dacro    |  |
|-|--->|         |  |
|-|--->|Fred     |  |
|-|--->|Ginny    |  |
|-|--->|Hermione |  |
|-|--->|         |  |
|-|--->|James    |  |
|-|--->|Kingsley |  |
|-|--->|Luna     |  |
|-|--->|Minerva  |  |
|-|--->|Neville  |  |
|-|--->|         |  |
|-|--->|Petunia  |  |
|-|--->|         |  |
|-|--->|Ron      |  |
|-|--->|Severus  |  |
|-|--->|         |  |
|-|--->|         |  |
|-|--->|Vernon   |  |
|-|--->|         |  |
|-|--->|         |  |
|-|--->|         |  |
|-|--->|Zacharias|  |
```

se existirem multiplos nomes com a mesma primeira letra, pode-se adiciona-los a uma lista encadeada


```
| -|--->|Albus    |  |
| -|--->|         |  |
| -|--->|Cedric   |  |
| -|--->|Dacro    |  |
| -|--->|         |  |
| -|--->|Fred     |  |
| -|--->|Ginny    |  |
| -|--->|Hermione | -|--->|Harry    | -|--->|Hagrid   |  |
| -|--->|         |  |
| -|--->|James    |  |
| -|--->|Kingsley |  |
| -|--->|Luna     |  |
| -|--->|Minerva  |  |
| -|--->|Neville  |  |
| -|--->|         |  |
| -|--->|Petunia  |  |
| -|--->|         |  |
| -|--->|Ron      |  |
| -|--->|Severus  |  |
| -|--->|         |  |
| -|--->|         |  |
| -|--->|Vernon   |  |
| -|--->|         |  |
| -|--->|         |  |
| -|--->|         |  |
| -|--->|Zacharias|  |
```
O array tem 26 ponteiros, sendo alguns deles com valor `NULL` e outros apontando para um nome em um nó (node), e esses podem apontar apontar para outro nome em outro nó.

Pode-se descrever cada nó no código como: 

```
typedef struct node
{
    char word[LONGEST_WORD + 1];
    struct node *next;
}
node;
```

pra melhorar o entendimento, podemos imaginar o modelo mental da recursividade no codigo. onde uma estrutura node tem uma 'string' e um ponteiro 'next' do tipo node, sendo node uma estrutura com uma 'string' e um ponteiro 'next' do tipo node... 

então no exemplo acima cada node terá um array de caracteres já alocados, com tamanho `LONGEST_WORD + 1`, nomeado `word`, então, o ponteiro `next` vai apontar para outro node, se ele existir.

Para criar uma hash table, pode-se escrever:

```
node *hash_table[NUMBER_OF_BUCKETS];
```

a tabela será um array de ponteiros que apontam para nós de tamanho `NUMBER_OF_BUCKETS`.

Para decidir qual balde, ou local que o array será colocado, pode-se usar um 'Hash function' que recebe a entrada e cria um indice ou local. No exemplo acima, a função hash retorna um indice correspondente à primeira letra do nome, como '0' para 'Albus' e '25' para 'Zacharias'

Pode-se classificar um baralho embaralhado, dividindo-o em quatro baldes, cada um rotulado por um naipe, e depois classificar cada um dos naipes.

Pode-se classificar cadeias menores na tabela hash, usando duas letras em vez de uma:


```
   | -|--->|         |  |
   | -|--->|         |  |
Ha | -|--->|Harry    | -|--->|Hagrid   |  |
Hb | -|--->|         |  |
Hc | -|--->|         |  |
Hd | -|--->|         |  |
He | -|--->|Hermione |  |
Hf | -|--->|         |  |
   | -|--->|         |  |
   | -|--->|         |  |
   | -|--->|         |  |
```

e então teriamos 676 baldes, para todas as combinações das duas primeiras letras.

pode-se adicionar mais uma letra, porém, será necessario ainda mais espaço na memória. Alguns desses baldes vão ficar vazios, mas provavelmente só precisariamos de uma etapa para procurar um valor, reduzindo o tempo de execução da pesquisa.

O tempo de execução do pior caso para a pesquisar na hash table é O(n), tendo em vista que todos os valores podem, teoricamente estar no mesmo balde, porém, na prática o tempo de execução será bem mais rápido.

## tries

outra estrutura de dados chamada de trie (pronunciada try e é abreviação de "retrieval"), uma trie é uma tree com arrays nos nós.

```
 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|
 ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯
```

cada array contendo as localizações que representam cada letra, AZ.

Para cada palavra, a primeira letra apontará para um array, onde a próxima letra válida apontará para outro array e assim por diante, até chegar a um valor booleano indicando o fim de de uma palavra válida, marcada com `$`


```
               H                                    
|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|
 ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯\¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯
                 \
 A                \
|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|
 ¯\¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯
   \              
    \        G    
|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|
 ¯ ¯ ¯ ¯ ¯ ¯ ¯\¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯
               \
                \                  R
|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|
 ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯/¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯
                                 /
                 I              /  
|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|
 ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯\¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯
                   \
       D            \
|¯|¯|¯|$|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|¯|
 ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯
```

e com vários nomes, é possivel a visualização do espaço sendo reaproveitado para as primeiras letras que são compartilhadas.

podemos definir uma trie no código como:

```
typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;
```

então em cada nó, ou array, temos um valor booleano que indica se é uma palavra válida (com valor `$` no nosso exemplo). Em seguida, teremos um array de tamanho `SIZE_OF_ALPHABET` que aponta para outros nós, com nome `children`.

a altura da árvore será o comprimento da palavra mais longa que queremos armazenar (será 4 se o nome for jorge).

e mesmo que a estrutura de dados tenha diversas palavras, o tempo máximo de busca será apenas o comprimento da palavra que estamos procurando. Sendo assim um n máximo fixo, equivalendo então a uma constante, `O(1)`, para inserção e para busca.

Mas em tudo temos um tradeoff, e o custo disso é muito espaço de armazenamento, para armazenar principalemente os ponteiros nulos.

## Queue

queue é uma estrura de dados abstrata, equivalente a pessoas esperando em uma fila, onde o pirmeiro valor inserido será o primeiro valor a ser retirado da fila, no conceito de "primeiro a entrar, primerio a sair" (FIFO, First In First Out), então podemos dar `enqueue` para adicionar valores nessa fila e dar dequeue para remover elementos 

## Stack

stack é outra estrura de dados abstrata, equivalentes a uma pilha de pratos, onde o primeiro valor inserido será o ultimo a ser retirado da pilha, no conceito de "primeiro a entrar, ultimo a sair" (LIFO, Last In First Out).

## Dictionary

Um restaurante pode colocar pedidos de comida em várias prateleiras com áreas, cada uma rotulada com a primeira letra do nome do cliente. Este é um exemplo de dicionário, onde podemos mapear chaves para valores.
