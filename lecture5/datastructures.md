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


