#include "util.h"

int validarNumeroPositivo(float numero) {
    return numero > 0;
}

int validarQuantidade(int quantidade) {
    return quantidade >= 0;
}

int validarTextoPreenchido(char texto[]) {
    return texto[0] != '\0';
}

