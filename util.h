#ifndef UTIL_H
#define UTIL_H

/* Validacoes gerais (nao dependem de nenhuma lista), reaproveitaveis por
   qualquer parte do sistema. */

int validarNumeroPositivo(float numero);   /* numero > 0 */
int validarQuantidade(int quantidade);     /* quantidade >= 0 */
int validarTextoPreenchido(char texto[]);  /* tem pelo menos 1 caractere visivel */
int validarPrateleira(char prateleira);    /* CORRECAO: nova, so aceita A, B, C ou D */

int validarSemPontoEVirgula(char texto[]); /* nao contem ';' (separador dos arquivos) */

/* Leitura segura: sempre consomem a linha inteira, sem sobras no buffer. */
void lerLinha(char destino[], int tamanho);  /* le ate o Enter; descarta o excedente */
int lerInteiro(int *valor);                  /* 1 se a linha e so um inteiro, senao 0 */
int lerDecimal(float *valor);                /* 1 se a linha e so um numero, senao 0 */

#endif
