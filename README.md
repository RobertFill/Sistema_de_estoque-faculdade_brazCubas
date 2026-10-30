# Sistema de Estoque

Sistema de controle de estoque em C, feito para a disciplina da faculdade (Braz Cubas). Roda no terminal, guarda produtos e categorias em arquivos de texto e é dividido em módulos.

## Funcionalidades

Menu principal:

```
1 - Cadastrar Produto
2 - Listar Produtos
3 - Pesquisar Produto      (submenu: Por código, Por nome, Voltar)
4 - Alterar Estoque de um Produto
5 - Remover Produto
6 - Categorias             (submenu: Cadastrar Categoria, Listar Categorias, Voltar)
7 - Sair
```

- **Produto:** código, nome, prateleira (A, B, C ou D), preço unitário, quantidade em estoque, disponibilidade e categoria.
- **Disponibilidade** é calculada pelo sistema (1 se a quantidade for maior que zero, senão 0) e recalculada a cada alteração de estoque.
- **Categorias:** cadastro e listagem. O produto só pode ser cadastrado em uma categoria existente, e sempre é exibido com o nome da categoria.
- **Alterar estoque:** entrada soma à quantidade; saída subtrai, mas é recusada se deixar o estoque negativo.
- **Remover produto:** exclusão lógica (`ativo = 0`). O produto some das listagens e pesquisas, mas continua na memória e no arquivo, e seu código não pode ser reutilizado.
- **Persistência:** os dados são carregados ao iniciar e salvos ao escolher **7 - Sair**. Se um arquivo não existir, a lista correspondente começa vazia.

## Limites e validações

| Item | Regra |
|---|---|
| Produtos | até 50 |
| Categorias | até 20 |
| Código (produto e categoria) | inteiro positivo e único |
| Nome (produto e categoria) | não pode ser vazio nem só espaços, nem conter `;` |
| Prateleira | exatamente um caractere: A, B, C ou D |
| Preço | maior que zero |
| Quantidade | maior ou igual a zero |

Textos maiores que o campo (50 caracteres para produto, 30 para categoria) são cortados, sem afetar as perguntas seguintes.

## Estrutura do projeto

| Arquivo | Conteúdo |
|---|---|
| `main.c` | Apenas os menus: lê a opção e chama as funções dos módulos |
| `produto.h` / `produto.c` | Struct `Produto`, cadastro, listagem, pesquisa, estoque, remoção e arquivo de produtos |
| `categoria.h` / `categoria.c` | Struct `Categoria`, cadastro, listagem e arquivo de categorias |
| `util.h` / `util.c` | Validações genéricas (número positivo, texto preenchido, prateleira, sem `;`) e leitura segura de linha, inteiro e decimal |

Regra de organização: validações que dependem de uma lista (código repetido, categoria inexistente) ficam no módulo do domínio; validações genéricas ficam no `util`.

## Arquivos de dados

Criados na pasta onde o programa é executado:

- `categorias.txt`: uma categoria por linha, no formato `codigo;nome`
- `produtos.txt`: um produto por linha, no formato `codigo;nome;prateleira;quantidade;preco;disponivel;ativo;categoria_codigo`

Os arquivos são regravados por completo ao sair do programa. Um `produtos.txt` antigo, sem a coluna de prateleira, ainda é lido (assume prateleira `A`).

## Como compilar e executar

Linux / macOS / Windows com GCC:

```bash
gcc -o sistema_estoque main.c produto.c categoria.c util.c
./sistema_estoque
```

Dev-C++: abra `Sistema_Estoque.dev` e compile com F11.
