# Singly-Linked List

Uma lista encadeada é uma estrutura que possui dois elementos:
* um dado com um tipo especifico (int, char, float...)
* e um ponteiro apontando para um nó com o mesmo tipo de dados.

Desse jeito, um conjunto de nós juntos pode ser pensado como uma corrente sendo formada de elementos que podem ser seguindas do inicio até o fim.

```
typedef struct sllist
{
    VALUE val;
    struct sllist *next;
}
sllist;
```

para trabalhar com listas encadeadas de forma efetiva, existe um número de operações que precisamos entender:

1. Criar uma lista encadeada quando ela ainda não existir.
2. Procurar na lista um elemento que estamos procurando.
3. Inserir um novo nó na lista.
4. Deletar um unico elemento da lista.
5. Deletar a lista toda e liberar a memória alocada para ela.

* Criar a lista encadeada:

```
sllnode *create(VALUE val);
```

* Procurar na lista em busca de um elemento:

```
bool find(sslnode *val head, VALUE val);
```

* Inserir um novo nó na lista:

```
sslnode *insert(sslnode *head, VALUE val);
```

* Deletar a lista:

```
void destroy(sslnode *head);
```
