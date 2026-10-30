#include <stdio.h>
#include "produto.h"
#include "categoria.h"

// Submenu para gerenciamento de categorias
void menu_categorias(Categoria categorias[], int *total_categorias) {
    int opcao;
    do {// sub menu de categoras
        printf("\n=== SUBMENU CATEGORIAS ===\n");
        printf("1 - Cadastrar Categoria\n");
        printf("2 - Listar Categorias\n");
        printf("3 - Voltar\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {// Validação da entrada do usuário para evitar loops infinitos.
            while (getchar() != '\n');//usada para ler um único caractere vindo da entrada padrão do teclado como o enter.
            opcao = 0;
        }

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
                printf("Opcao invalida!\n"); //Mantém o loop até a escolha de voltar
        }
    } while (opcao != 3);
}

int main() { // Declaração das coleções em memória e seus contadores
    Categoria categorias[MAX_CATEGORIAS];
    int total_categorias = 0;

    Produto produtos[MAX_PRODUTOS];/* Carrega os dados dos arquivos na inicializacao
    								carregar_categorias(categorias, &total_categorias);
   									carregar_produtos(produtos, &total_produtos);*/
    int total_produtos = 0;

    // Carrega os dados dos arquivos na inicializacao
    carregar_categorias(categorias, &total_categorias);
    carregar_produtos(produtos, &total_produtos);

    int opcao;
    do {
        		//Menu Principal atualizado
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Pesquisar Produto\n");
        printf("4 - Alterar Estoque de um Produto\n");
        printf("5 - Remover Produto\n");
        printf("6 - Categorias\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = 0;
        }

        switch (opcao) {// percorre os arquivos
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
                alterar_estoque(produtos, total_produtos);
                break;
            case 5:
                remover_produto(produtos, total_produtos);
                break;
            case 6:
                menu_categorias(categorias, &total_categorias);
                break;
            case 7:
                // Salva os dados antes de fechar o programa
                salvar_categorias(categorias, total_categorias);
                salvar_produtos(produtos, total_produtos);
                printf("Dados salvos com sucesso. Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 7);// laço

    return 0;
}
