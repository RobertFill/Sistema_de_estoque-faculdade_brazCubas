#include <stdio.h>
#include <string.h>
#include "produto.h"
#include "util.h" // CORRECAO: validacoes genericas
#include "categoria.h"

/* o produto .c e a lógica de programação relacionada com os produtos no sistema de estoque*/


     /* Retorna o índice do produto pelo código na lista em memória; retorna -1 se não encontrar.*/
int buscar_produto_por_codigo(Produto produtos[], int total, int codigo) {
    int i;
    for (i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

/* CORRECAO: funcao pedida na Tarefa 2 - busca por nome usando strcmp.
   Devolve a posicao ou -1. Ignora produtos removidos (ativo == 0). */
int buscar_produto_por_nome(Produto produtos[], int total, char nome[]) {
    int i;
    for (i = 0; i < total; i++) {
        if (produtos[i].ativo == 1 && strcmp(produtos[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void exibir_produto(Produto p, Categoria categorias[], int total_categorias) {
    int pos = buscar_categoria_por_codigo(categorias, total_categorias, p.categoria_codigo);
    // Busca o nome da categoria relacionada pelo código cadastrado
    
    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Prateleira: %c\n", p.prateleira); // CORRECAO: mostra a prateleira
    printf("Quantidade: %d\n", p.quantidade);
    printf("Preco unitario: R$ %.2f\n", p.preco_unitario);
    printf("Disponibilidade: %s\n", p.disponivel ? "Disponivel" : "Indisponivel"); // Exibe a disponibilidade do produto

    if (pos != -1) {
        printf("Categoria: %s\n", categorias[pos].nome);
    } else {
        printf("Categoria: Desconhecida\n");
    }
    printf("-----------------------------------\n");
}
	// Realiza o cadastro de um novo produto e validações
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

    // Validação de entrada para o Código (deve ser único e positivo)
    do {
        printf("Digite o codigo do produto (numero positivo): ");
        if (scanf("%d", &p.codigo) != 1) {
            while (getchar() != '\n');
            p.codigo = -1;
        }
        if (!validarNumeroPositivo((float)p.codigo)) { // CORRECAO: via util
            printf("Codigo invalido! Deve ser um numero positivo.\n");
        } else if (buscar_produto_por_codigo(produtos, *total_produtos, p.codigo) != -1) {
            printf("Codigo ja cadastrado! Tente outro.\n"); // erro se repetir o mesmo código já cadastrado
            p.codigo = -1;
        }
    } while (!validarNumeroPositivo((float)p.codigo));

    while (getchar() != '\n'); // Limpa buffer

    // Nome
    do {
        printf("Digite o nome do produto: ");
        lerLinha(p.nome, sizeof(p.nome)); /* CORRECAO: descarta o excedente */
            /*obtem o texto de um arquivo e precisa de 3 argumentos para funcionar, p.nome(Destino)
		e a variável/vetor onde o texto digitado será guardado, sizeof(p.nome) (Tamanho Máximo)
		e o limite de caracteres que a função pode ler,
		sizeof calcula automaticamente o tamanho total da string p.nome (por exemplo, 50 caracteres).*/
	
        if (!validarTextoPreenchido(p.nome)) { // CORRECAO: via util
            printf("Nome nao pode ser vazio!\n");
        } else if (!validarSemPontoEVirgula(p.nome)) {
            printf("Nome nao pode conter ponto e virgula (;)!\n");
        }
    } while (!validarTextoPreenchido(p.nome) || !validarSemPontoEVirgula(p.nome));

    // CORRECAO: leitura e validacao da prateleira (A, B, C ou D)
    char linha_prat[16];
    do {
        printf("Digite a prateleira (A, B, C ou D): ");
        lerLinha(linha_prat, sizeof(linha_prat));
        /* CORRECAO: exige exatamente 1 caractere (antes "AB" virava 'A') */
        p.prateleira = (strlen(linha_prat) == 1) ? linha_prat[0] : '?';
        if (!validarPrateleira(p.prateleira)) {
            printf("Prateleira invalida! Use apenas A, B, C ou D.\n");
        }
    } while (!validarPrateleira(p.prateleira));

    	// Quantidade
    do {
        printf("Digite a quantidade: ");
        if (!lerInteiro(&p.quantidade) || !validarQuantidade(p.quantidade)) { // CORRECAO: linha inteira, sem sobras
            p.quantidade = -1;
            printf("Quantidade invalida! Digite um valor maior ou igual a zero.\n");
        }
    } while (p.quantidade < 0);

    	// Preço unitario
    do {
        printf("Digite o preco unitario: ");
        if (!lerDecimal(&p.preco_unitario) || !validarNumeroPositivo(p.preco_unitario)) { // CORRECAO: preco deve ser > 0, sem sobras
            p.preco_unitario = -1.0;
            printf("Preco invalido! Digite um valor maior que zero.\n");
        }
    } while (p.preco_unitario < 0);

    	// vincula com Categoria
    printf("\n--- Categorias Disponiveis ---\n");
    listar_categorias(categorias, total_categorias);

    int pos_cat = -1;
    do {
        printf("Digite o codigo da categoria do produto: ");
        if (scanf("%d", &p.categoria_codigo) != 1) {
            while (getchar() != '\n');
            p.categoria_codigo = -1;
        }
        pos_cat = buscar_categoria_por_codigo(categorias, total_categorias, p.categoria_codigo);
        if (pos_cat == -1) {
            printf("Categoria nao encontrada! Escolha um codigo da lista acima.\n");
        }
    } while (pos_cat == -1);

    // Regras automaticas: disponibilidade e status ativo, Calculado automaticamente a partir da quantidade
    p.disponivel = (p.quantidade > 0) ? 1 : 0;
    p.ativo = 1;// // Todo produto novo entra como ativo na lista

    produtos[*total_produtos] = p;
    (*total_produtos)++;
    printf("Produto cadastrado com sucesso!\n");

    // CORRECAO: resumo com todos os campos ao final do cadastro (Tarefa 1)
    printf("\n--- Resumo do Produto ---\n");
    exibir_produto(p, categorias, total_categorias);
}

void listar_produtos(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias) {
    printf("\n--- Lista de Produtos ---\n");
    int i, exibidos = 0;
    for (i = 0; i < total_produtos; i++) {
        if (produtos[i].ativo == 1) {  // Ignora produtos inativos,Pula inativos
            exibir_produto(produtos[i], categorias, total_categorias);
            exibidos++;
        }
    }
    if (exibidos == 0) {
        printf("Nenhum produto ativo cadastrado.\n");
    }
}

void pesquisar_produto(Produto produtos[], int total_produtos, Categoria categorias[], int total_categorias) {
    if (total_produtos == 0) {
        printf("\nNenhum produto cadastrado para pesquisar.\n");
        return;
    }

    int opcao_sub;
    do {
		//Submenu de pesquisa codigo - nome - e voltar
        printf("\n--- SUBMENU PESQUISAR PRODUTO ---\n");
        printf("1 - Por codigo\n");
        printf("2 - Por nome\n");
        printf("3 - Voltar\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao_sub) != 1) {
            while (getchar() != '\n');
            opcao_sub = 0;
        }

        if (opcao_sub == 1) {
            int codigo;
            printf("\nDigite o codigo do produto: ");
            if (scanf("%d", &codigo) != 1) {
                while (getchar() != '\n');
                printf("Codigo invalido!\n");
                continue;
            }

            int pos = buscar_produto_por_codigo(produtos, total_produtos, codigo); //Verifica se encontrou E se está ativo
            if (pos != -1 && produtos[pos].ativo == 1) {
                printf("\n--- Produto Encontrado ---\n");
                exibir_produto(produtos[pos], categorias, total_categorias);
            } else {
                printf("Produto nao encontrado ou inativo.\n");
            }
        } else if (opcao_sub == 2) {
            // CORRECAO: pesquisa por nome agora usa a funcao buscar_produto_por_nome (strcmp)
            char nome[50];
            int pos;
            while (getchar() != '\n'); // Limpa buffer
            printf("\nDigite o nome do produto: ");
            lerLinha(nome, sizeof(nome));

            pos = buscar_produto_por_nome(produtos, total_produtos, nome);
            if (pos != -1) {
                printf("\n--- Produto Encontrado ---\n");
                exibir_produto(produtos[pos], categorias, total_categorias);
            } else {
                printf("Nenhum produto encontrado com o nome informado.\n");
            }
        } else if (opcao_sub == 3) {
            printf("Voltando ao menu principal...\n");
        } else {
            printf("Opcao invalida!\n");
        }
    } while (opcao_sub != 3);
}
			//NOVA FUNCAO Alterar Estoque de um Produto
void alterar_estoque(Produto produtos[], int total_produtos) {
    if (total_produtos == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    int codigo;
    printf("\n--- Alterar Estoque de um Produto ---\n");
    printf("Digite o codigo do produto: ");
    if (scanf("%d", &codigo) != 1) {
        while (getchar() != '\n');
        printf("Codigo invalido! Operacao cancelada.\n");
        return;
    }

    int pos = buscar_produto_por_codigo(produtos, total_produtos, codigo);
	//Se o produto não existir ou estiver inativo (ativo == 0), avisa e retorna
    if (pos == -1 || produtos[pos].ativo == 0) {
        printf("Erro: Produto nao encontrado ou inativo!\n");
        return;
    }

    int tipo, qtd;
    //Pergunta o tipo de movimentacao (Entrada/Saida) e a quantidade
    printf("Produto selecionado: %s (Estoque atual: %d)\n", produtos[pos].nome, produtos[pos].quantidade);
    printf("Tipo de movimentacao:\n");
    printf("1 - Entrada (chegada de mercadoria)\n");
    printf("2 - Saida (venda ou retirada)\n");
    printf("Escolha uma opcao: ");
    if (scanf("%d", &tipo) != 1 || (tipo != 1 && tipo != 2)) {
        while (getchar() != '\n');
        printf("Opcao invalida! Operacao cancelada.\n");
        return;
    }

    printf("Digite a quantidade: ");
    if (scanf("%d", &qtd) != 1 || qtd <= 0) {
        while (getchar() != '\n');
        printf("Quantidade invalida! A quantidade deve ser um numero inteiro positivo.\n");
        return;
    }

    if (tipo == 1) { // entrada, soma a quantidade
        produtos[pos].quantidade += qtd;
        printf("Entrada realizada com sucesso! Novo estoque: %d\n", produtos[pos].quantidade);
    } else { // saída, subtrai se não ficar negativo; se for maior que o estoque, bloqueia
        if (qtd > produtos[pos].quantidade) {
            printf("Erro: Operacao nao realizada! A quantidade de Saida (%d) eh maior que o estoque atual (%d).\n", qtd, produtos[pos].quantidade);
            return;
        }
        produtos[pos].quantidade -= qtd;
        printf("Saida realizada com sucesso! Novo estoque: %d\n", produtos[pos].quantidade);
    }

    // Recalcula a disponibilidade
    produtos[pos].disponivel = (produtos[pos].quantidade > 0) ? 1 : 0;
}
		//NOVA FUNCAO Remover Produto(Exclusão Lógica)
void remover_produto(Produto produtos[], int total_produtos) {
    if (total_produtos == 0) {
        printf("\nNenhum produto cadastrado para remover.\n");
        return;
    }

    int codigo;
    printf("\n--- Remover Produto (Exclusao Logica) ---\n");
    printf("Digite o codigo do produto que deseja remover: ");
    if (scanf("%d", &codigo) != 1) {
        while (getchar() != '\n');
        printf("Codigo invalido! Operacao cancelada.\n");
        return;
    }

    int pos = buscar_produto_por_codigo(produtos, total_produtos, codigo);
    if (pos == -1 || produtos[pos].ativo == 0) {
        printf("Erro: Produto nao encontrado ou ja removido!\n");
        return;
    }

    produtos[pos].ativo = 0; // usa exclusão logia (não apagado fisicamente do disco ou da memória)
    printf("Produto '%s' (Codigo %d) removido com sucesso!\n", produtos[pos].nome, produtos[pos].codigo);
}
// Salva os produtos (CORRECAO: agora inclui a prateleira)
void salvar_produtos(Produto produtos[], int total) {
    FILE *f = fopen("produtos.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo para salvar produtos!\n");
        return;
    }
    int i;
    for (i = 0; i < total; i++) {
        fprintf(f, "%d;%s;%c;%d;%.2f;%d;%d;%d\n",
                produtos[i].codigo,
                produtos[i].nome,
                produtos[i].prateleira,
                produtos[i].quantidade,
                produtos[i].preco_unitario,
                produtos[i].disponivel,
                produtos[i].ativo,
                produtos[i].categoria_codigo);
    }
    fclose(f);
}

// Carrega os produtos. Arquivo inexistente = lista vazia.
void carregar_produtos(Produto produtos[], int *total) {
    FILE *f = fopen("produtos.txt", "r");
    *total = 0;
    if (f == NULL) {
        return;
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), f) != NULL && *total < MAX_PRODUTOS) {
        if (strlen(linha) <= 1) continue;
        Produto p;
        // CORRECAO: formato novo, com prateleira (8 campos)
        int lidos = sscanf(linha, "%d;%49[^;];%c;%d;%f;%d;%d;%d",
                           &p.codigo, p.nome, &p.prateleira, &p.quantidade,
                           &p.preco_unitario, &p.disponivel, &p.ativo, &p.categoria_codigo);
        if (lidos == 8 && validarPrateleira(p.prateleira)) {
            produtos[*total] = p;
            (*total)++;
        } else {
            // Compatibilidade com arquivo antigo, sem prateleira (7 campos):
            // assume prateleira 'A' (sera regravado no formato novo ao sair)
            lidos = sscanf(linha, "%d;%49[^;];%d;%f;%d;%d;%d",
                           &p.codigo, p.nome, &p.quantidade, &p.preco_unitario,
                           &p.disponivel, &p.ativo, &p.categoria_codigo);
            if (lidos == 7) {
                p.prateleira = 'A';
                produtos[*total] = p;
                (*total)++;
            }
        }
    }
    fclose(f);
}
