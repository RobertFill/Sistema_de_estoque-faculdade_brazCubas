#include <stdio.h>
#include <string.h>
#include "produto.h"
#include "categoria.h"

int buscar_produto_por_codigo(Produto produtos[], int total, int codigo) {
    int i;
    for (i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void exibir_produto(Produto p, Categoria categorias[], int total_categorias) {
    int pos = buscar_categoria_por_codigo(categorias, total_categorias, p.categoria_codigo);

    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Preco: R$ %.2f\n", p.preco);

    if (pos != -1) {
        printf("Categoria: %s\n", categorias[pos].nome);
    } else {
        printf("Categoria: Desconhecida\n");
    }
    printf("-----------------------------------\n");
}

void cadastrar_produto(Produto produtos[], int *total_produtos, Categoria categorias[], int total_categorias) {
    if (total_categorias == 0) {
        printf("\nAtencao: Cadastre ao menos uma categoria antes de cadastrar um produto!\n");
        return;
    }

    if (*total_produtos >= MAX_PRODUTOS) {
        printf("\nLimite de produtos atingido!\n");
        return;
    }

    Produto p;
    printf("\n--- Cadastrar Produto ---\n");

    // Validação do Código do Produto
    do {
        printf("Digite o codigo do produto (numero positivo): ");
        if (scanf("%d", &p.codigo) != 1) {
            while (getchar() != '\n');
            p.codigo = -1;
        }
        if (p.codigo <= 0) {
            printf("Codigo invalido!\n");
        } else if (buscar_produto_por_codigo(produtos, *total_produtos, p.codigo) != -1) {
            printf("Codigo ja cadastrado!\n");
            p.codigo = -1;
        }
    } while (p.codigo <= 0);

    while (getchar() != '\n');

    // Nome
    do {
        printf("Digite o nome do produto: ");
        fgets(p.nome, sizeof(p.nome), stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0';
        if (strlen(p.nome) == 0) {
            printf("Nome nao pode ser vazio!\n");
        }
    } while (strlen(p.nome) == 0);

    // Quantidade
    do {
        printf("Digite a quantidade: ");
        if (scanf("%d", &p.quantidade) != 1 || p.quantidade < 0) {
            while (getchar() != '\n');
            p.quantidade = -1;
            printf("Quantidade invalida!\n");
        }
    } while (p.quantidade < 0);

    // Preço
    do {
        printf("Digite o preco: ");
        if (scanf("%f", &p.preco) != 1 || p.preco < 0) {
            while (getchar() != '\n');
            p.preco = -1.0;
            printf("Preco invalido!\n");
        }
    } while (p.preco < 0);

    // Vínculo com Categoria
    printf("\n--- Categorias Disponiveis ---\n");
    listar_categorias(categorias, total_categorias);

    int pos_cat = -1;
    do {
        printf("Digite o codigo da categoria do produto: ");
        scanf("%d", &p.categoria_codigo);
        pos_cat = buscar_categoria_por_codigo(categorias, total_categorias, p.categoria_codigo);
        if (pos_cat == -1) {
            printf("Categoria nao encontrada! Escolha um codigo da lista acima.\n");
        }
    } while (pos_cat == -1);

    produtos[*total_produtos] = p;
    (*total_produtos)++;
    printf("Produto cadastrado com sucesso!\n");
}

void listar_produtos(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias) {
    printf("\n--- Lista de Produtos ---\n");
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    int i;
    for (i = 0; i < total_produtos; i++) {
        exibir_produto(produtos[i], categorias, total_categorias);
    }
}

void pesquisar_produto(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias) {
    if (total_produtos == 0) {
        printf("\nNenhum produto para pesquisar.\n");
        return;
    }
    int codigo;
    printf("\nDigite o codigo do produto que deseja pesquisar: ");
    scanf("%d", &codigo);

    int pos = buscar_produto_por_codigo(produtos, total_produtos, codigo);
    if (pos != -1) {
        printf("\n--- Produto Encontrado ---\n");
        exibir_produto(produtos[pos], categorias, total_categorias);
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void salvar_produtos(Produto produtos[], int total) {
    FILE *f = fopen("produtos.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo para salvar produtos!\n");
        return;
    }
    int i;
    for (i = 0; i < total; i++) {
        fprintf(f, "%d;%s;%d;%.2f;%d\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].categoria_codigo);
    }
    fclose(f);
}

void carregar_produtos(Produto produtos[], int *total) {
    FILE *f = fopen("produtos.txt", "r");
    if (f == NULL) {
        *total = 0;
        return;
    }
    *total = 0;
    while (fscanf(f, "%d;%49[^;];%d;%f;%d\n", &produtos[*total].codigo, produtos[*total].nome, &produtos[*total].quantidade, &produtos[*total].preco, &produtos[*total].categoria_codigo) == 5) {
        (*total)++;
        if (*total >= MAX_PRODUTOS) break;
    }
    fclose(f);
}
