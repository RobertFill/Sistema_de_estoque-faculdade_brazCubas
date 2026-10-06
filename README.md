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
=============================
       MENU PRINCIPAL
=============================
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Sair
=============================
Escolha uma opcao: 1

--- CADASTRO DE PRODUTO ---
Codigo: 123
Nome: feijão
Prateleira (A, B, C ou D): a
Preco unitario: 2
Quantidade em estoque: 4

>>> Produto cadastrado com sucesso! <<<

----------------------------------------
Codigo               : 123
Nome                 : feijão
Prateleira           : a
Preco                : R$ 2.00
Quantidade em estoque: 4
Disponivel para venda: Sim (1)
----------------------------------------

=============================
       MENU PRINCIPAL
=============================
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Sair
=============================
Escolha uma opcao: 2

--- LISTA DE PRODUTOS (1/50) ---

----------------------------------------
Codigo               : 123
Nome                 : feijão
Prateleira           : a
Preco                : R$ 2.00
Quantidade em estoque: 4
Disponivel para venda: Sim (1)
----------------------------------------

=============================
       MENU PRINCIPAL
=============================
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Sair
=============================
Escolha uma opcao: 3

--- PESQUISAR PRODUTO ---
1. Por codigo
2. Por nome
Escolha o tipo de busca: 1
Digite o codigo do produto: 123

>>> Produto Encontrado! <<<

----------------------------------------
Codigo               : 123
Nome                 : feijão
Prateleira           : a
Preco                : R$ 2.00
Quantidade em estoque: 4
Disponivel para venda: Sim (1)
----------------------------------------

=============================
       MENU PRINCIPAL
=============================
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto
4 - Sair
=============================
Escolha uma opcao: 3

--- PESQUISAR PRODUTO ---
1. Por codigo
2. Por nome
Escolha o tipo de busca: 2
Digite o nome do produto: feijão

>>> Produto Encontrado! <<<

----------------------------------------
Codigo               : 123
Nome                 : feijão
Prateleira           : a
Preco                : R$ 2.00
Quantidade em estoque: 4
Disponivel para venda: Sim (1)
----------------------------------------

```

## Próximos passos (ideias de melhoria)

- Salvar dados em arquivo para persistência entre execuções.
- Busca de quantidade de preodutos cadastrados.
- Localizar o armazenamento onde produto se encontra.
 
