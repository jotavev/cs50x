## http-server

Na ultima semana usamos http-server, ele escuta conexões e requisições, e responde com conteúdo estático, por exemplo com arquivos HTML, mas não processa outros tipos de requisições, como por exemplo um input de um formulário preenchido pelo usuário.

Relembrando, uma URL pode parecer com: `http://example.com/` onde a barra indica a pagina padrão, ou `http://example.com/file.html` para um arquivo especifico. O arquivo pode estar em um diretório, por exemplo, `folder/file.html`, isso é conhecido como path. Um path pode ser chamado de route, que não precisa se referir a um caminho real/literal.

* Uma URL também pode incluir input de um formulário como por exemplo: 

```
http://www.example.com/route?key=value
```
onde o ? separa o path (ou route), da parte que contém parametros da requisição, que nesse caso é "key=value"

da pra separar os valores com &, por exemplo: 

```
http://www.example.com/route?key1=value1&key2=value2
```

## Flask 

Flask é um framework (Um framework é um conjunto estruturado de diretrizes, bibliotecas e ferramentas que fornecem uma maneira padronizada de abordar o desenvolvimento de software, varios humanos convencionaram diversas coisas para que não fosse preciso reinventar a roda todas as vezes ao iniciar um projeto) 

Existe uma maneira convencionada para se organizar um projeto em flask que basicamenete é:

```
app.py
requirements.txt
static/
templates/
```

`app.py` terá o código em python para o servidor web
`requiriments.txt` é a lista que inclui todas as libs que estamos usando no projeto
`static/` é o diretório onde ficarão os arquivos estáticos, como CSS e JS
`templates/` é o diretório onde ficarão os arquivos HTML do projeto

Outros frameworks web fazem de outra forma ok 

obs: 
```
request.args
request.form
```

# MVC
Model-View-Controller, é um padrão de design de software que facilita a troca de informações entre a interface do usuário e ao dados no banco

* model é responsável pelos dados e regras de negócio da aplicação

* view é responsável por apresentar os dados ao usuário e capturar as entradas do usuário

* controller é por gerenciar a interação entre o view e o controller

```
         ╭─── MODEL ◀──╮
         │             │
         │             │
      updates     manipulates
         │             │
         ▼             │
       VIEW       CONTROLLER
         │             │
       sees          uses
         │             ▲
         │             │
         ╰──▶ USER ────╯
```
no exemplo do flask:
o controler é onde está nosso código python
o view é onde está nosso HTML com jinja
e o model é nosso database, em sqlite, por exemplo


# Sessions e Cookies 

Session é como se fosse o carrinho de compras que mantém as informações, mesmo navegando em páginas diferentes do site.

Cookie é comumente usado para armazenar as informações de login do usário para que ele permaneça conectado entre sessões.
