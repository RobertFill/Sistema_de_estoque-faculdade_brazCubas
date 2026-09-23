#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int opcao;

    /* Variáveis do Produto*/
    
    int codigo;
    char nome[50];
    char prateleira;
    float preco;
    int quantidade;
    int disponivel;
    
while (1) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 2) {
            printf("Saindo...\n");
            break; // Fecha o loop do menu e encerra o programa
        }

        if (opcao == 1) {
            printf("\n--- CADASTRO DE PRODUTO ---\n");

            // 1. Código
            printf("Codigo: ");
            scanf("%d", &codigo);
            while (codigo <= 0) {
                printf("Invalido! Digite um codigo positivo: ");
                scanf("%d", &codigo);
            }

            // 2. Nome
            printf("Nome: ");
            fflush(stdin);
            gets(nome);

            // 3. Prateleira
            printf("Prateleira (A, B, C ou D): ");
            fflush(stdin);
            scanf("%c", &prateleira);
            while (prateleira != 'A' && prateleira != 'a' &&
                   prateleira != 'B' && prateleira != 'b' &&
                   prateleira != 'C' && prateleira != 'c' &&
                   prateleira != 'D' && prateleira != 'd') {
                printf("Invalida! Digite A, B, C ou D: ");
                fflush(stdin);
                scanf("%c", &prateleira);
            }

            // 4. Preço Unitário
            printf("Preco: ");
            scanf("%f", &preco);
            while (preco <= 0) {
                printf("Invalido! O preco deve ser maior que zero: ");
                scanf("%f", &preco);
            }

            // 5. Quantidade
            printf("Quantidade: ");
            scanf("%d", &quantidade);
            while (quantidade < 0) {
                printf("Invalida! Digite 0 ou mais: ");
                scanf("%d", &quantidade);
            }

            // Cálculo da disponibilidade
            disponivel = (quantidade > 0) ? 1 : 0;

            // Resumo
            printf("\n--- RESUMO DO PRODUTO ---\n");
            printf("Codigo: %d\n", codigo);
            printf("Nome: %s\n", nome);
            printf("Prateleira: %c\n", prateleira);
            printf("Preco: R$ %.2f\n", preco);
            printf("Estoque: %d\n", quantidade);
            printf("Disponivel: %d\n", disponivel);
        }
    }

	return 0;
}
