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
