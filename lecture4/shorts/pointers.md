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

