## Computer Science == Problem Solving
input -> [ ] -> output
a caixa preta entre a entrada e a saida é o computador resolvendo problemas, em ultima analise é dentro dessa caixa preta que roda o código que você escreve para solucionar problemas.

### Representação
no mundo dos computadores precisamos representar números, assim como no mundo dos humanos, nós humanos usamos o sistema decimal (temos 10 dedos) para representar números, os computadores usam o sistema binário.

### Letras 
não é só números que são representados por binários, o computador reprensenta, em ultima instancia, tudo com binários.

na tabela ascii o 'A' em binário é 1000001 ou 65 se convertido para decimal, o 'B' é 66. https://www.asciichart.com/

### unicode
no mundo existem varios idiomas, e varios caracteres nesses idiomas, bem mais que 127 caracteres (contido na tabela ascii), por exemplo no portugues, usamos 'ã é ç', agora imagine os caracteres arabes ou russos, ou até mesmo carecteres muito importantes como: '🤪', então temos a tabela unicode 🔝 para isso. Enquanto a ascii tem 8 bit (128 possibilidades), unicode por ir até 32 bits (4 bilhoes possibilidades)

### algoritmos
é uma sequencia finita de ações/passos executaveis que visa solucionar um determinado problema.

um exemplo é procurar um nome em uma lista telefonica. podemos foliar de pagina em pagina até achar, ou, ir até o meio da lista, ver se a inicial da palavra que procuramos está pra frente ou pra trás, descartamos a outra parte que ela não está contida, e repetimos até acharmos a letra (<- recursividade)

### pseudo código 
Pick up phone book 
Open to middle of phone book
Look at page 
If person is on the page 
    Call person
Else if person is earlier in book
    Open to middle of left half of book
    Go back to line 3
Else if person is later in book
    Open to middle of right half of book  
    Go back to line 3
Else
    Quit

### scracth
é um ambiente de programação web ou download que usa blocos para codar

