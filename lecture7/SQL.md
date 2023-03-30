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

para criar um banco de dados a partir do csv
```
$ sqlite3 favorites.db
sqlite> .mode csv
sqlite> .import favorites.csv favorites
```
para consultar o esquema da tabela
```
$ sqlite3 favorites.db
sqlite> .schema
CREATE TABLE IF NOT EXISTS "favorites"(
  "Timestamp" TEXT,
  "title" TEXT,
  "genres" TEXT
);
```
para selecionar ou ler dados
```
sqlite> SELECT title FROM favorites;
+------------------------------------+
|                title               |
+------------------------------------+
| How i met your mother              |
| The Sopranos                       |
| Friday Night Lights                |
```
o comando basicamente é `SELECT coluna FROM tabela;` e também dá pra selecionar mais coisas com `SELECT title, genre FROM favorites;` e para selecionar tudo de uma tabela da pra usar o `*`, sendo assim fica `SELECT * FROM tabela;`

e com SQL temos alguns modificadores, que são funções incoporadas à linguagem:
```
AVG 
COUNT 
DISTINCT
LOWER 
MAX 
MIN
UPPER
``` 
o comando distinct pode ser usado assim:
```
sqlite> SELECT DISTINCT(title) FROM favorites;
+------------------------------------+
|                title               |
+------------------------------------+
| How i met your mother              |
| The Sopranos                       |
| Friday Night Lights                |
```
podemos combinar um ou mais modificadores:
```
sqlite> SELECT DISTINCT(UPPER(title)) FROM favorites;
+------------------------------------+
|                title               |
+------------------------------------+
| HOW I MET YOUR MOTHER              |
| THE SOPRANOS                       |
| FRIDAY NIGHT LIGHTS                |
```
podemos ver o total de elementos:
```
sqlite> SELECT COUNT(title) FROM favorites;
+--------------+
| COUNT(title) |
+--------------+
| 157          |
+--------------+
```
podemos adicionar mais comandos:
```
WHERE
LIKE 
ORDER BY
LIMIT
GROUP BY
```

o comando `WHERE` funciona como uma expressão booleana
o comando `LIKE` funciona para fazer aproximações de palavras parecidas
o comando `LIMIT` vai definir o numero de resultados que a busca vai gerar

um exemplo de limit:

```
sqlite> SELECT title FROM favorites LIMIT 10;
+-----------------------+
|         title         |
+-----------------------+
| How i met your mother |
| The Sopranos          |
| Friday Night Lights   |
| Family Guy            |
| New Girl              |
| Friends               |
| Office                |
| Breaking Bad          |
| Modern Family         |
| Office                |
+-----------------------+
```

um exemplo do comando select:
```
sqlite> SELECT title FROM favorites WHERE title LIKE "%office%";
+-------------+
|    title    |
+-------------+
| Office      |
| Office      |
| The Office  |
| The Office  |
| The Office  |
| The Office  |
| The Office  |
| The Office  |
| The Office  |
| The Office  |
| The Office  |
| the office  |
| The Office  |
| ThE OffiCE  |
| The Office  |
| Thevoffice  |
+-------------+
```

podemos relacionar duas tabelas diferentes por um id, fazendo com que os dados fiquem com um design melhor

usando o exemplo da tabela anterior, onde era uma tabela chamada de `favorites` com uma coluna `title` e outra coluna `genres`.

ao invés disso podemos criar duas tabelas diferentes uma com nome do show e outra com o genero do show, as duas relacionadas por um id

então teremos uma duas tabelas relacionas de um banco de dados relacional

```
CREATE TABLE shows (id INTEGER, title TEXT NOT NULL, PRIMARY KEY(id));
CREATE TABLE genres (show_id INTEGER, genre TEXT NOT NULL, FOREIGN KEY(show_id) REFERENCES shows(id));
```

uma tabela com nome `shows` que tem duas colunas, uma `id` e outra `title`, onde o `id` é do tipo inteiro e é uma `PRIMARY KEY` e `title` um texto não nulo, ou seja, comose fosse um `required` do html.
outra com nome `genres` que tem duas colunas, `show_id` e `genre`, onde o `id_show` é do tipo inteiro e é uma `FOREIGN KEY` e `genre` é um texto não nulo.

o conceito de chaves para nosso contexto:
Uma chave é um atributo ou conjunto de atributos que é usado para identificar exclusivamente uma linha (ou registro) em uma tabela. (onde atributo pode ser entendido como coluna.)

A chave pode ser usada para evitar duplicatas e permitir que tabelas se relacionem com a tabela que possui a chave  :


a chave primária funcina como um idendificador para uma das linhas da tabela, pode ser uma unica coluna (assim como no exemplo), ou mais, que juntas, identificam a linha.
a chave estrangeira representa o relacionamento entre duas tabelas, um atributo que é uma chave primária 








para um output mais organizado no `~/.sqliterc` adcione:
```
.mode column
.headers on
.separator ROW "\n"
.nullvalue NULL
.mode box  
.timer on    
```
