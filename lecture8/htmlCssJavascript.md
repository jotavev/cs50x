# The internet

Uma rede de computadores é um sistema que permite que os dispositivos de computação se comuniquem entre si, podem ser conectadas sem fio (WiFi ou LoRa), ou com cabos (cobre ou fibra ótica).

A internet é o conjunto de redes de computadores que, espalhados por todas as regiões do planeta, conseguem trocar dados e mensagens utilizando um protocolo comum. 

Os roteadores tem um papel fundamental para a internet pois eles conectam diferentes redes de computadores e permitem a comunicação entre elas. Eles encaminham pacotes de dados de uma rede para outra, escolhendo a melhor rota com base nos endereços IP e outras informações. Além disso, podem ser usados para compartilhar uma única conexão de internet entre vários dispositivos em uma rede.

# TCP/IP

Para que essa comunicação seja estabelecida entre os dispositivos, é preciso de haver um protocolo de comunicação comum, ou seja, um conjunto de regras e normas que descrevem como as informações devem ser trocadas, por exemplo, um protocolo para falar com uma pessoa é primeiro cumprimentar ela, com um aperto de mão por exemplo, ou, usar máscaras em hospitais, ou seja, protocolo é algo padronizado (e documentado).

O TCP/IP são dois protocolos que os computadores usam para se comunicar nos dias de hoje. 

Fazendo uma analogia simples, com entregas, o pacote a ser entregue são os dados, IP é o endereço da pessoa, e TCP é o livro de regras metódicas que o carteiro deve seguir para garantir a entrega confiável da encomenda (dados).

O TCP estabelece uma conexão confiável e orientada à conexão entre dois dispositivos, divide os dados em pacotes, enumera os pacotes, envia eles, quando eles chegam, ele reordena-os e se houver pacotes perdidos ou danificados ele pede a retransmissão para que tudo seja entregue corretamente e sem erros.

Outra coisa importante são portas, as portas são usadas no TCP para permitir que vários processos ou aplicativos se comuniquem com a rede ao mesmo tempo usando o mesmo endereço de IP, cada processo ou aplicativo é identificado por um número exclusivo, na analogia das entregas, as portas são como salas comerciais dentro do endereço da casa. (por exemplo 192.168.0.1:80 onde 192.168.0.1 é o endereço e 80 é a porta).

Esses números são padronizados, 80 é HTTP, 443 é HTTPS e por ai vai.

Existe também o UDP que é o carteiro que entrega os pacotes sem verificar se foram entregues com sucesso, só entrega e pronto. O que é menos confiável no que tange a integridade dos dados, mas é mais rápido e isso é muito útil no contexto de streaming de video e áudio, video chamadas, jogos online, monitoramento de sensores em tempo real. Mesmo que alguns pacotes sejam perdidos no caminho, nesse contexto a velocidade é mais importante que a confiabilidade.

# DNS 

Quando digitamos buscamos por algum site, não digitamos o endereço "142.250.80.68", por exemplo, e sim "http://www.google.com".

O DNS é como se fosse um dicionario que quando tu põe o domínio "www.barfoo.ru" ele automaticamente te leva para o endereço certinho do site daquele domínio, como se fosse uma hash table.


# HTTP

É o protocolo que os navegadores e os servidores web usam para se comunicar e isso diferencia a internet da web. A internet é como se fosse o baixo nível, os cabos e a tecnologia que move os pacotes seguindo aquelas instruções. A web é uma aplicação que foi contruida em cima das tecnologias da internet, útil o HTTP ou HTTPS para transferir dados entre o servidor e o cliente e é acessada por meio de URLs (Uniform Resource Locators)

assindo como exemplo o site:

https://www.example.com/

o "/" no fim do endereço indica a raiz do diretório, ou seja a pagina inicial do site. 

https://www.example.com/path

o path pode ser um arquivo.html ou diretório/arquivo.html por exemplo assim:

https://www.example.com/diretório/file.html

e o "example.com" é o nome do domínio de fato.

No primeiro exemplo temos o FQDN (Fully Qualified Domain Name) onde www é o subdominio opcional (poderia ser chat, blog, mail e etc) que serve para identificar o serviço especifico que o domínio principal oferece (lembrando que é completamente opcional, porém é adotado como convenção) e o com é o TLD (Top-level domain) ou extensão de domínio, que não é opcional e indica qual a categoria ou finalidade do dominio (com é comercial, edu educacional, org organização sem fins lucrativos, mil militar, gov governamental).

Uma empresa que usa o subdomio para todos os seus serviços é a google, onde tudo está embaixo do domínio google.com e os subdominios determinam qual o nome do servidor especifico, por exemplo o gmail é "mail.google.com" o maps é "maps.google.com" e isso facilita na coleta de dados.

Essa é uma boa estratégia para conseguir todas as permissões para acessar dados do usuário, uma vez que o usuário aceita o pedido de permissão para a localização quando está usando o maps, aceitando assim dar a permissão para o domínio google.com, agora tudo sob o dominio google.com tem acesso a localização, aumentando assim a coleta de dados e oferecendo produtos e anuncios mais personalizados. Obviamente respeitando todas as politicas de privacidade.

# HTTP Requests Responses

no HTTP existem métodos, que servem para fazer requisições do usuário para o servidor, e são eles:

* GET, é usado para buscar recursos no servido, por exemplo, quando se digita uma url no navegador, ele faz uma requisição GET para o servidor do site para carregar a página solicitada.

* POST, é usado para enviar informações para o servidor, por exemplo, em fomulários de cadastro e login, quando um usuário preenche um formuário as informações são enviadas por um método POST.

* PUT, é usado para atualizar recursos já existentes, por exemplo, em um ecomerce o cliente pode usar o médoto PUT para atualizar seu endereço de entrega ou método de pagamento no seu perfil de usuário.

* DELETE, pra deletar.

em uma analogia o cliente é um cliente de restaurante, que faz um pedido para o garçom (método) e aguarda uma resposta. A cozinha que nesse caso é o servidor, recebe o pedido do garçom, processa e separa a resposta para ser entregue de volta para o cliente.

Então após receber uma requisição HTTP do cliente, o servidor processa a requisição e prepara uma responsta para enviar para o cliente, supondo que a requisição foi:
``` 
GET / HTTP/1.1
Host: www.example.com
```
a resposta será parecida com:

```
HTTP/1.1 200 OK
Content-Type: text/html
```
retornando o status 200 OK, onde quer dizer isso mesmo, tudo correto.
e retornando o conteúdo solicidade, e isso também é padroniza, nesse exemplo foi uma pagina html, mas poderia ser image/jpeg, image/png, application/pdf, audio/mpeg, video/mp4 ou outros diferentes tipos de conteúdo que são conehcidos como tipo MIME e cada tipo de arquivo tem um tipo MIME associado.

ela pode responder outro status e alguns deles são:

```
301 Moved Permanently
302 Found
304 Not Modified
307 Temporary Redirect
401 Unauthorized
403 Forbidden
404 Not Found
418 I'm a Teapot
500 Internal Server Error
503 Service Unavailable
```
