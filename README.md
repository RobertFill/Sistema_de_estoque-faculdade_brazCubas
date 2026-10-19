# sistema Controle de estoque e registro de produtos.
## Programa simpleis que cria, controla saida e monitora preço, e localiza prateleras.
### Ferramenta ultilizada: Dev C++

### Funcionalidades

- Cadastro de código, estoque inicial e preço unitário do produto
- Registro de vendas com atualização automática do estoque
- Bloqueio de vendas quando a quantidade solicitada é maior que o estoque
- Loop para registrar múltiplas vendas na mesma execução
- Resumo final com estoque restante e total vendido

### Como compilar e executar

### Linux / macOS
```bash
gcc -o sistema_estoque main.c
./sistema_estoque
```

### Windows (usando Dev-C++, Code::Blocks ou similar)
Abra o arquivo `main.c` na IDE e compile normalmente (F9 ou o botão de compilar/executar).

## Exemplo de uso

```

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 1

--- Cadastrar Produto ---
Digite o codigo do produto (numero positivo): 3
Digite o nome do produto: miojo
Digite a quantidade: 2
Digite o preco: 3

--- Categorias Disponiveis ---

--- Lista de Categorias ---
Codigo: 1 | Nome: porta
Digite o codigo da categoria do produto: 1
Produto cadastrado com sucesso!

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 2

--- Lista de Produtos ---
Codigo: 123
Nome: arroz
Quantidade: 3
Preco: R$ 20.00
Categoria: porta
-----------------------------------
Codigo: 3
Nome: miojo
Quantidade: 2
Preco: R$ 3.00
Categoria: porta
-----------------------------------

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 3

Digite o codigo do produto que deseja pesquisar: 123

--- Produto Encontrado ---
Codigo: 123
Nome: arroz
Quantidade: 3
Preco: R$ 20.00
Categoria: porta
-----------------------------------

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 4

=== SUBMENU CATEGORIAS ===
1 - Cadastrar Categoria
2 - Listar Categorias
3 - Voltar
Escolha uma opcao: 1

--- Cadastrar Categoria ---
Digite o codigo da categoria (numero positivo): 5
Digite o nome da categoria: portaB
Categoria cadastrada com sucesso!

=== SUBMENU CATEGORIAS ===
1 - Cadastrar Categoria
2 - Listar Categorias
3 - Voltar
Escolha uma opcao: 2

--- Lista de Categorias ---
Codigo: 1 | Nome: porta
Codigo: 5 | Nome: portaB

=== SUBMENU CATEGORIAS ===
1 - Cadastrar Categoria
2 - Listar Categorias
3 - Voltar
Escolha uma opcao: 3
Voltando ao menu principal...

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 4

=== SUBMENU CATEGORIAS ===
1 - Cadastrar Categoria
2 - Listar Categorias
3 - Voltar
Escolha uma opcao: 4
Opcao invalida!

=== SUBMENU CATEGORIAS ===
1 - Cadastrar Categoria
2 - Listar Categorias
3 - Voltar
Escolha uma opcao: 3
Voltando ao menu principal...

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 2

--- Lista de Produtos ---
Codigo: 123
Nome: arroz
Quantidade: 3
Preco: R$ 20.00
Categoria: porta
-----------------------------------
Codigo: 3
Nome: miojo
Quantidade: 2
Preco: R$ 3.00
Categoria: porta
-----------------------------------

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 1

--- Cadastrar Produto ---
Digite o codigo do produto (numero positivo): 7
Digite o nome do produto: feijão
Digite a quantidade: 7
Digite o preco: 50

--- Categorias Disponiveis ---

--- Lista de Categorias ---
Codigo: 1 | Nome: porta
Codigo: 5 | Nome: portaB
Digite o codigo da categoria do produto: 5
Produto cadastrado com sucesso!

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 2

--- Lista de Produtos ---
Codigo: 123
Nome: arroz
Quantidade: 3
Preco: R$ 20.00
Categoria: porta
-----------------------------------
Codigo: 3
Nome: miojo
Quantidade: 2
Preco: R$ 3.00
Categoria: porta
-----------------------------------
Codigo: 7
Nome: feijão
Quantidade: 7
Preco: R$ 50.00
Categoria: portaB
-----------------------------------

=== MENU PRINCIPAL ===
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Categorias
5 - Sair
Escolha uma opcao: 4

=== SUBMENU CATEGORIAS ===
1 - Cadastrar Categoria
2 - Listar Categorias
3 - Voltar
Escolha uma opcao: 2

--- Lista de Categorias ---
Codigo: 1 | Nome: porta
Codigo: 5 | Nome: portaB

=== SUBMENU CATEGORIAS ===
1 - Cadastrar Categoria
2 - Listar Categorias
3 - Voltar
Escolha uma opcao:

```

## Próximos passos (ideias de melhoria)

- Salvar dados em arquivo para persistência entre execuções.
- Busca de quantidade de preodutos cadastrados.
- Localizar o armazenamento onde produto se encontra.
 
