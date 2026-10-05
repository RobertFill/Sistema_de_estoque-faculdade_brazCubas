#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 50

// Estrutura do Produto conforme requisitado
typedef struct {
    int codigo;
    char nome[50];
    char prateleira;
    float preco;
    int quantidade;
    int disponivel; // 1 = Sim, 0 = Nao
} Produto;

// Protótipos das funções
void exibirProduto(Produto p);
int buscarPorCodigo(Produto lista[], int total, int codigo);
int buscarPorNome(Produto lista[], int total, char nome[]);
void cadastrarProduto(Produto lista[], int *total);
void listarProdutos(Produto lista[], int total);
void pesquisarProduto(Produto lista[], int total);

int main() {
    Produto estoque[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\n=============================\n");
        printf("       MENU PRINCIPAL        \n");
        printf("=============================\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Pesquisar Produto\n");
        printf("4 - Sair\n");
        printf("=============================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); // Limpa o buffer caso digite letra
            opcao = 0;
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarProduto(estoque, &totalProdutos);
                break;
            case 2:
                listarProdutos(estoque, totalProdutos);
                break;
            case 3:
                pesquisarProduto(estoque, totalProdutos);
                break;
            case 4:
                printf("\nPrograma encerrado.\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Exibe os dados de um unico produto
void exibirProduto(Produto p) {
    printf("\n----------------------------------------\n");
    printf("Codigo               : %d\n", p.codigo);
    printf("Nome                 : %s\n", p.nome);
    printf("Prateleira           : %c\n", p.prateleira);
    printf("Preco                : R$ %.2f\n", p.preco);
    printf("Quantidade em estoque: %d\n", p.quantidade);
    printf("Disponivel para venda: %s\n", p.disponivel ? "Sim (1)" : "Nao (0)");
    printf("----------------------------------------\n");
}

// Busca produto pelo codigo (compativel com Dev-C++)
int buscarPorCodigo(Produto lista[], int total, int codigo) {
    int i;
    for (i = 0; i < total; i++) {
        if (lista[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Busca produto pelo nome (compativel com Dev-C++)
int buscarPorNome(Produto lista[], int total, char nome[]) {
    int i;
    for (i = 0; i < total; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Cadastra um novo produto
void cadastrarProduto(Produto lista[], int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("\nErro: A lista de produtos esta cheia (limite de %d produtos)!\n", MAX_PRODUTOS);
        return;
    }

    Produto novo;
    int codigo;

    printf("\n--- CADASTRO DE PRODUTO ---\n");

    // Validação de unicidade de código
    do {
        printf("Codigo: ");
        scanf("%d", &codigo);
        if (buscarPorCodigo(lista, *total, codigo) != -1) {
            printf("Erro: O codigo %d ja esta cadastrado! Digite um codigo unico.\n", codigo);
        }
    } while (buscarPorCodigo(lista, *total, codigo) != -1);

    novo.codigo = codigo;

    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);

    printf("Prateleira (A, B, C ou D): ");
    scanf(" %c", &novo.prateleira);

    printf("Preco unitario: ");
    scanf("%f", &novo.preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &novo.quantidade);

    // Calculo automatico do campo 'disponivel'
    novo.disponivel = (novo.quantidade > 0) ? 1 : 0;

    lista[*total] = novo;
    (*total)++;

    printf("\n>>> Produto cadastrado com sucesso! <<<\n");
    exibirProduto(novo);
}

// Lista todos os produtos
void listarProdutos(Produto lista[], int total) {
    int i;
    printf("\n--- LISTA DE PRODUTOS (%d/%d) ---\n", total, MAX_PRODUTOS);
    if (total == 0) {
        printf("Nenhum produto foi cadastrado.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        exibirProduto(lista[i]);
    }
}

// Submenu de pesquisa
void pesquisarProduto(Produto lista[], int total) {
    if (total == 0) {
        printf("\nNenhum produto cadastrado para realizar busca.\n");
        return;
    }

    int opcaoBusca;
    int indice = -1;

    printf("\n--- PESQUISAR PRODUTO ---\n");
    printf("1. Por codigo\n");
    printf("2. Por nome\n");
    printf("Escolha o tipo de busca: ");
    scanf("%d", &opcaoBusca);

    if (opcaoBusca == 1) {
        int cod;
        printf("Digite o codigo do produto: ");
        scanf("%d", &cod);
        indice = buscarPorCodigo(lista, total, cod);
    } else if (opcaoBusca == 2) {
        char nome[50];
        printf("Digite o nome do produto: ");
        scanf(" %[^\n]", nome);
        indice = buscarPorNome(lista, total, nome);
    } else {
        printf("Opcao de busca invalida!\n");
        return;
    }

    if (indice != -1) {
        printf("\n>>> Produto Encontrado! <<<\n");
        exibirProduto(lista[indice]);
    } else {
        printf("\nNenhum produto foi encontrado.\n");
    }
}
