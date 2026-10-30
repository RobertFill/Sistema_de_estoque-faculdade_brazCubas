#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

/* Isola as logicas repetitivas de validacao do resto do codigo,
   mantendo os arquivos principais mais limpos e organizados. */

int validarNumeroPositivo(float numero) {
    return numero > 0;
}

int validarQuantidade(int quantidade) {
    return quantidade >= 0;
}

/* CORRECAO: antes so testava texto vazio; agora tambem rejeita texto
   formado so por espaços (precisa de pelo menos um caractere visivel). */
int validarTextoPreenchido(char texto[]) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (!isspace((unsigned char)texto[i])) {
            return 1;
        }
    }
    return 0;
}

/* CORRECAO: nova validacao generica da prateleira (A, B, C ou D). */
int validarPrateleira(char prateleira) {
    return prateleira == 'A' || prateleira == 'B' ||
           prateleira == 'C' || prateleira == 'D';
}

/* Texto nao pode conter ';', senao quebra o formato dos arquivos .txt. */
int validarSemPontoEVirgula(char texto[]) {
    return strchr(texto, ';') == NULL;
}

/* Le uma linha inteira. Se o usuario digitar mais que cabe em 'destino',
   o excesso e descartado (nao vaza para o proximo campo). */
void lerLinha(char destino[], int tamanho) {
    int c;
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    size_t n = strcspn(destino, "\n");
    if (destino[n] == '\n') {
        destino[n] = '\0';
    } else {
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

/* Aceita somente se a linha tiver um inteiro e mais nada ("5abc" e rejeitado). */
int lerInteiro(int *valor) {
    char buf[64], extra;
    lerLinha(buf, sizeof(buf));
    return sscanf(buf, " %d %c", valor, &extra) == 1;
}

int lerDecimal(float *valor) {
    char buf[64], extra;
    lerLinha(buf, sizeof(buf));
    return sscanf(buf, " %f %c", valor, &extra) == 1;
}
