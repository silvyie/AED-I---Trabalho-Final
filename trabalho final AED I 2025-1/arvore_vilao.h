#ifndef ARVORE_VILAO_H
#define ARVORE_VILAO_H

#include "vilao.h"

typedef struct no_arvore_vilao NoArvoreVilao;

NoArvoreVilao* inserir_vilao(NoArvoreVilao* raiz, Vilao* v);
void imprimir_viloes_ordem(NoArvoreVilao* raiz);
void liberar_arvore_vilao(NoArvoreVilao* raiz);

#endif