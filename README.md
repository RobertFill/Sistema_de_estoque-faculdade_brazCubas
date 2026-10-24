# Sistema de Estoque

Programa simples em C para controle de estoque e registro de vendaas.

## Funcionalidades

- Cadastro de código, estoque inicial e preço unitário do produto
- Registro de vendas com atualização automática do estoque
- Bloqueio de vendas quando a quantidade solicitada é maior que o estoque
- Loop para registrar múltiplas vendas na mesma execução
- Resumo final com estoque restante e total vendido

## Como compilar e executar

### Linux / macOS
```bash
gcc -o sistema_estoque main.c
./sistema_estoque
```

### Windows (usando Dev-C++, Code::Blocks ou similar)
Abra o arquivo `main.c` na IDE e compile normalmente (F9 ou o botão de compilar/executar).

## Exemplo de uso

```
Codigo do produto: 1
Estoque inicial: 5
Preco unitario: 2.50

Estoque atual: 5
Quantidade vendida: 3
Venda registrada! Total desta venda: R$ 7.50
Deseja registrar outra venda? (1 = sim, 0 = nao): 0

----- Resumo -----
Codigo do produto: 1
Estoque restante: 2
Total vendido em R$: 7.50
```

## Próximos passos (ideias de melhoria)

- Cadastro de múltiplos produtos (usando um array ou struct)
- Salvar dados em arquivo para persistência entre execuções
- Menu de opções (cadastrar, vender, consultar, sair)
