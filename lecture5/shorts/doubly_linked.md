# Listas encadeadas

a principal diferença entra uma singly e doubly é que na doubly você tem o endereço do próximo nó e do nó anterior:

```
typedef struct dllist
{
    VALUE val;
    struct ddlist *prev;
    struct ddlist *next;
}
dllnode;
```


