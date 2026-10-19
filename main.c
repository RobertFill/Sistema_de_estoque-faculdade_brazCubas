#include <stdio.h>
#include "produto.h"
#include "categoria.h"

void menu_categorias(Categoria categorias[], int *total_categorias) {
    int opcao;
    do {
        printf("\n=== SUBMENU CATEGORIAS ===\n");
        printf("1 - Cadastrar Categoria\n");
        printf("2 - Listar Categorias\n");
        printf("3 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_categoria(categorias, total_categorias);
                break;
            case 2:
                listar_categorias(categorias, *total_categorias);
                break;
            case 3:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);
}

int main() {
    Categoria categorias[MAX_CATEGORIAS];
    int total_categorias = 0;

    Produto produtos[MAX_PRODUTOS];
    int total_produtos = 0;

    // Carrega os dados dos arquivos na inicialização
    carregar_categorias(categorias, &total_categorias);
    carregar_produtos(produtos, &total_produtos);

    int opcao;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Pesquisar Produto\n");
        printf("4 - Categorias\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_produto(produtos, &total_produtos, categorias, total_categorias);
                break;
            case 2:
                listar_produtos(produtos, total_produtos, categorias, total_categorias);
                break;
            case 3:
                pesquisar_produto(produtos, total_produtos, categorias, total_categorias);
                break;
            case 4:
                menu_categorias(categorias, &total_categorias);
                break;
            case 5:
                // Salva os dados antes de fechar o programa
                salvar_categorias(categorias, total_categorias);
                salvar_produtos(produtos, total_produtos);
                printf("Dados salvos com sucesso. Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
