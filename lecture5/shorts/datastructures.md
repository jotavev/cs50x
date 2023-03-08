# Estruturas de dados

Uma `estrutura de dados` é um modo de armazenar e organizar dados com o objetivo de facilitiar acesso e modificações. Não existe bala de prata, então, nenhuma estrutura de dados única funciona bem para todas as finalidades e, por isso, é importante conhecer pontos fortes e as limitações de várias delas. 

# Sumário da estrura de dados

ao o que eu entendi temos 4 jeitos principais de armazenar dados e os demais jeitos são variações desses 4, ou seja, aprendendo muito bem o conceito desses 4, o restante é de fácil compreensão, e eles são:

* Arrays
* Linked Lists 
* Hash Tables
* Tries 

trees e heaps, por exemplo, são similares a tries, stacks e queues são bastante similares a arrays e linked lists. mas os 4 principais cobrem o que estamos estudando em C, nesse momento. (Leitura de dever de casa: Algoritmos - Teoria e Prática)

## Arrays

* Inserção ruim - muitos deslocamentos são necessários para adicionar um elemento no meio
* Exclusão ruim - muitos deslocamentos são necessários depois de deletar um elemento
* Pesquisa boa - acesso randomico, tempo constante
* Relativamente fácil de ordenar 
* Relativamente pequeno em termos de tamanho
* Precisam de tamanhos fixos, sem flexibilidade

## Linked Lists

* Inserção fácil - só adicionar na frente 
* Exclusão fácil - depois de encontrar o elemento 
* Pesquisa ruim - precisa de confiar em busca linear
* Relativamente dificil de organizar - a menos que você esteja disposto a comprometer a inserção super rapida, e for ordenando durante a inserção
* Relativamente pequeno (mas não tão pequeno quanto array)

## Hash Tables

* Inseção fácil - tem apenas dois passos: hash e inserir
* Exclusão fácil - depois de encontrar o elemento
* Pesquisa é melhor que Linked Lists
* Organizar: não é a estrutura de dados se o objetivo é esse (melhor usar array)
* Ocupa bastante espaço dependendo da quantidade de dados

## Tries

* Inserção é complexa - precisa de bastante memoria na heap, mas depois de construída fica mais fácil
* Exclusão é fácil - apenas precisa de dar free em um nó 
* Pesquisa é rápida - não tanto quanto array, mas é
* Organizar, basicamente não precisa, tendo em vista que ele se organiza no momento da criação 
* Ocupa bastante espaço 


