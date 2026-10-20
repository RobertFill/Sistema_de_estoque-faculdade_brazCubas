#ifndef PRODUTO_H
#define PRODUTO_H

#include "categoria.h"

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco_unitario;
    int categoria_codigo; // Novo campo da Tarefa 4
} Produto;

void cadastrar_produto(Produto produtos[], int *total_produtos, Categoria categorias[], int total_categorias);
void listar_produtos(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias);
void pesquisar_produto(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias);
void exibir_produto(Produto p, Categoria categorias[], int total_categorias);
void salvar_produtos(Produto produtos[], int total);
void carregar_produtos(Produto produtos[], int *total);

#endif
