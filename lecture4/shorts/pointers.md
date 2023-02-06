# Pointers
* Ponteiros nos fornecem uma diferente maneira de passar dados entre funções
** Quando passamos um valor para uma função, na verdade estamos passando uma cópia desses dados para a função. 
** Existe uma exceção para essa regra de passagem de valor, 

se usarmos ponteiros ao invés de usar cópias de variaveis, podemos passar as variáveis entre as funções, de uma maneira diferente. Como no exemplo de `swap.c`. Isso representa uma grande mudança em nossa capacidade de trabalhar com dados.

Digamos que eu tenho um caderno cheio de anotações, e eu gostaria que você atualizasse algumas anotações. 
se usarmos o jeito antigo (sem ponteiros), seria como se você pegasse meu caderno e tira uma xerox de todas as anotaços, fizesse as alterações e me retornasse com as xerox das anotações, e agora cabe a mim como `main` decidir o que fazer com as novas anotações nas xeroxs, se eu vou implementar elas no meu caderno ou não.

portanto há muitos passos envolvidos nessa operação.

utilizando pointers, eu literalemnte te dei o caderno e uma caneta para que as alterações fossem feitas nele mesmo, sem necessidade de cópias e sem precisar de eu receber um retorno e tratar ele. 

então o números de passos envolvidos enssa operação é diminuto em relação a outra. 

-

O ponteiro mais simples disponivel em `C` é o `NULL`
* e é isso mesmo, ele não aponta para lugar algum (porém ele é util)
* Se você não definir qual o endereço do ponteiro imediatamente, então é imprescindivel definir o ponteiro para nulo.
* Para checar o valor do ponteiro (pra ver se ele é nulo por ex) basta usar o operador `==`

- 

* Outra maneira de criar um ponteiro é simplesmente extrair o endereço de alguma variavel existente. 
* Para extrair basta usar o operador `&`


* se `x` é uma variavel do tipo `int`, o `&x` é o ponteiro para o valor do tipo int `x`.

* se `arr` for um array de double, então `&arr[i]` é o ponteiro para valor `i` desse array.

* array é apenas um ponteiro e é por isso que quando passamos um array como argumento para uma função a função muda de fato o conteúdo do array, pois ele é um ponteiro.

-

* o principal proposito do ponteiro é permitir que possamos modificar ou inspecionar o local para onde o ponteiro aponta (o dado que ele aponta)

* se temos um ponteiro do tipo char chamado `pc`, então `*pc` é como nos referimos ao dado que está na memória armazenado na variavél `pc`

então `*` é o operador de dereferencia é como se ele significasse `vá até a referencia` e acessasse o dado nesse local da memória, e permitindo que você manipule o dado a vontade.

* um exemplo é como se você estivesse visitando seu vizinho, se você tem o endereço dele só significa que você tem o endereço dele. você precisa de `ir até o endereço` e só assim você consegue interagir com ele.

- 

* O que acontece quando tentamos dereferenciar um ponteiro cujo o valor é NULL, falando `vá até a referencia`? `Segmentation fault`

* isso é bom por causa que isso é uma forma de defesa contra manipulações perigosas de ponteiros que apontam para lugares desconhecidos.
* Por isso é recomendado setar os ponteiros para NULL imediatamente, para que se sem querer você altere ele, a falha de segmentação acontaça, e você não toque na memoria que não deveria.

-

```
int *p;
```

* o valor de p é um endereço, pois todos os ponteiros são endereços
* É possivel dereferenciar o `p` usando o operador `*`
* se eu dereferenciar ele, o valor iremos achar nessa localização é o valor inteiro de p.

- 

```
int *px, py, pz
```

no exemplo acima só px é um ponteiro para um inteiro, py e pz são inteiros. 
(meio obvio mas antigamente o padrão era usar `int* p` então o exemplo acima ficaria `int* px, py, pz`, onde obviamente não muda nada e somente o px será ponteiro. 
Com a nova forma padrão de fazer isso, agora fica ordens de grandeza mais facil de compreender isso ok)

-

| DataType | Tamanho (em bytes) |
|:--------:|:------------------:|
| int | 4 |
| char | 1 |
| float | 4 |
| double | 8 |
| long long | 8 |
| string | 4 ou 8 |

* o motivo de ser 4 ou 8 é porque depende do sistema.

| DataType | Tamanho (em bytes) |
|:--------:|:------------------:|
| int | 4 |
| char | 1 |
| float | 4 |
| double | 8 |
| long long | 8 |
| char* | 4 ou 8 |

Se você estiver usando cs50 ide,em um sistema de 64 bits, o tamanho de char* é 8.
Cada endereço na memória tem 64 bits de comprimento.

Se você estiver usando cs50 ide,em um sistema de 32 bits, o tamanho de char* é 4.
Cada endereço na memória tem 32 bits de comprimento.

| DataType | Tamanho (em bytes) |
|:--------:|:------------------:|
| int | 4 |
| char | 1 |
| float | 4 |
| double | 8 |
| long long | 8 |
| char*, int*, float*, double* | 4 ou 8 |

E, de fato, quaisquer tipos de dados e um ponteiro para qualquer tipo de dados, uma vez que ponteiros são apenas endereços, são 4 ou 8 bytes. 

é por isso que devemos sempre usar a função `sizeof`
