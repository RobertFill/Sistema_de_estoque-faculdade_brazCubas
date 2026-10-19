#include <stdio.h>
#include <string.h>
#include "categoria.h"

int buscar_categoria_por_codigo(Categoria categorias[], int total, int codigo) {
    int i;
    for (i = 0; i < total; i++) {
        if (categorias[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void cadastrar_categoria(Categoria categorias[], int *total) {
    if (*total >= MAX_CATEGORIAS) {
        printf("\nLimite de categorias atingido (%d)!\n", MAX_CATEGORIAS);
        return;
    }

    Categoria c;

    printf("\n--- Cadastrar Categoria ---\n");

    // Validação do Código
    do {
        printf("Digite o codigo da categoria (numero positivo): ");
        if (scanf("%d", &c.codigo) != 1) {
            while (getchar() != '\n'); // Limpa buffer
            c.codigo = -1;
        }
        if (c.codigo <= 0) {
            printf("Codigo invalido! Deve ser um numero positivo.\n");
        } else if (buscar_categoria_por_codigo(categorias, *total, c.codigo) != -1) {
            printf("Codigo ja cadastrado! Tente outro.\n");
            c.codigo = -1;
        }
    } while (c.codigo <= 0);

    while (getchar() != '\n'); // Limpa buffer

    // Validação do Nome
    do {
        printf("Digite o nome da categoria: ");
        fgets(c.nome, sizeof(c.nome), stdin);
        c.nome[strcspn(c.nome, "\n")] = '\0'; // Remove o \n

        if (strlen(c.nome) == 0) {
            printf("O nome nao pode ficar em branco!\n");
        }
    } while (strlen(c.nome) == 0);

    categorias[*total] = c;
    (*total)++;
    printf("Categoria cadastrada com sucesso!\n");
}

void listar_categorias(Categoria categorias[], int total) {
    int i;
    printf("\n--- Lista de Categorias ---\n");
    if (total == 0) {
        printf("Nenhuma categoria cadastrada.\n");
        return;
    }
    for (i = 0; i < total; i++) {
        printf("Codigo: %d | Nome: %s\n", categorias[i].codigo, categorias[i].nome);
    }
}

void salvar_categorias(Categoria categorias[], int total) {
    FILE *f = fopen("categorias.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo para salvar categorias!\n");
        return;
    }
    int i;
    for (i = 0; i < total; i++) {
        fprintf(f, "%d;%s\n", categorias[i].codigo, categorias[i].nome);
    }
    fclose(f);
}

void carregar_categorias(Categoria categorias[], int *total) {
    FILE *f = fopen("categorias.txt", "r");
    if (f == NULL) {
        *total = 0; // Arquivo não existe ainda, inicia lista vazia
        return;
    }
    *total = 0;
    while (fscanf(f, "%d;%29[^\n]\n", &categorias[*total].codigo, categorias[*total].nome) == 2) {
        (*total)++;
        if (*total >= MAX_CATEGORIAS) break;
    }
    fclose(f);
}
