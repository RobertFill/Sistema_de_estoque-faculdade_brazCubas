#ifndef PRODUTO_H
#define PRODUTO_H

#include "categoria.h"

#define MAX_PRODUTOS 50 /* CORRECAO: a Tarefa 2 pede 50 posicoes (antes era 100) */

/* o produto.h modulo de produtos: define o que e um Produto e quais acoes
   podem ser feitas com ele */

typedef struct {
    int codigo;
    char nome[50];
    char prateleira;      /* CORRECAO: campo que faltava (so A, B, C ou D) */
    int quantidade;
    float preco_unitario;
    int disponivel;       /* 1 se quantidade > 0, senao 0 */
    int ativo;            /* 1 para ativo, 0 para removido (exclusao logica) */
    int categoria_codigo;
} Produto;

/* CORRECAO: buscas agora declaradas no .h */
int buscar_produto_por_codigo(Produto produtos[], int total, int codigo);// atribuição de codigos
int buscar_produto_por_nome(Produto produtos[], int total, char nome[]);

void cadastrar_produto(Produto produtos[], int *total_produtos, Categoria categorias[], int total_categorias);
void listar_produtos(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias);
void pesquisar_produto(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias);
void alterar_estoque(Produto produtos[], int total_produtos);
void remover_produto(Produto produtos[], int total_produtos);
void exibir_produto(Produto p, Categoria categorias[], int total_categorias);
void salvar_produtos(Produto produtos[], int total);
void carregar_produtos(Produto produtos[], int *total);

#endif
