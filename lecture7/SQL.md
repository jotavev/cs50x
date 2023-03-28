# Criar, ler, atualizar e apagar dados
na semana anterior vimos como manipular dados de um csv usando python e a lib "csv".
e isso é muito util se estamos recebendo diversos dados e precisamos tratar eles e etc. 
Porém existem ferramentas diferentes, ou até melhores, para o mesmo trabalho. 
E dependendo da aplicação, cabe ao desenvolvedor escolher a que mais se adapta ao contexto, pois existem tradeoffs de cada decisão.
Por exemplo, usar martelo e pregos é uma boa forma de juntar taboas de madeira, tem baixo custo, porém requer uma certa destreza e é um pouco lento, já uma pistola de pregos é bem mais rápida, não precisa de tantas habilidades pra ser produtivo, porém já tem um custo mais elevado em comparação com martelo. 

# SQL 
Uma ferramenta muito útil para criação de soluções robustas, é um banco de dados relacional.
A linguagem de consulta estruturada, é a linguagem padrão para banco de dados relacional.
Um banco de dados relacional está mais próximo ao um programas de planilhas que de um simples arquivo csv.
Porém um banco de dados relacional pode armazenar muito mais dados que uma simples planilha.
Ou seja são mais escalaveis que as outras duas soluções.

# CRUD

```
CREATE, INSERT
READ 
DELETE
UPDATE, DROP
...
```

a sintaxe para criar uma tabela para um banco de dados com SQL
```
CREATE TABLE table (column type, ...);
```
onde `table` é o nome da tabela e o que está em parentesis é onde vai estar uma ou mais colunas, sempre com seus tipos, pois SQL é uma linguagem fortemente tipada, similar ao C.

