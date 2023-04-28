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



