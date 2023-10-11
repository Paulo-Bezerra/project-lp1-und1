# Projeto 1 - Sistema gerenciador de pedidos de uma lanchonete
## Um sistema de pedidos de lanches, automático.

### Funcionalidades
A lanchonete vende sanduíches e sucos. O sistema tem dois tipos de usuários com as seguintes funcionalidades.
#### O perfil de cliente tem as seguintes funcionalidades
- Listar todos os sanduíches cadastrados
- Listar todos os sucos cadastrados
- Escolher o lanche (sanduíche, suco)
- Calcular o valor do lanche (o que foi salvo no carrinho)
- Ver elementos do carrinho (lanche escolhido)
- Excluir um item do carrinho
#### O perfil de gerente tem as seguintes opções funcionalidades
- Proteção por meio de uma senha de acesso para evitar que estranhos acessem informações indevidas
- Listar todos os sanduíches cadastrados
- Listar todos os sucos cadastrados
- Adicionar um novo sanduíche
- Adicionar um novo suco
- Alterar o preço de um sanduíche
- Alterar o preço de um suco
- Excluir um sanduíche
- Excluir um suco

### Tecnologias
- C++
- Makefile
- Bash

### Pré-requisitos
- Uma distribuição Linux (o qualquer sistema operacional UNIX, acredito)
- Compilador C++
- Um shell/terminal para executar os comandos (bash)

### Instalação e execução
Para compilar basta descompactar a pasta, abrir o terminal na pasta descompactada e executar o comando `make run`, caso queira apenas compilar basta executar apenas o comando `make`, o que criara um executável chamado “program”, para executá-lo, após a compilação, basta o digitar `./program` na raiz da pasta descompactada.

Caso desejar apagar todos os binários e arquivos de objeto basta executar o comando `make clean` pelo terminal na raiz da pasta descompactada.
