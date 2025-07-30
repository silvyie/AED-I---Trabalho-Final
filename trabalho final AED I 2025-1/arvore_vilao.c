#include <stdio.h>
#include <stdlib.h>
#include "arvore_vilao.h"

struct no_arvore_vilao {
    Vilao* vilao;
    NoArvoreVilao* esq;
    NoArvoreVilao* dir;
};

NoArvoreVilao* inserir_vilao(NoArvoreVilao* raiz, Vilao* v) {
    if (raiz == NULL) {
        NoArvoreVilao* novo = (NoArvoreVilao*)malloc(sizeof(NoArvoreVilao));
        novo->vilao = v;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (nivel_habilidade_vilao(v) < nivel_habilidade_vilao(raiz->vilao)) {
        raiz->esq = inserir_vilao(raiz->esq, v);
    } else {
        raiz->dir = inserir_vilao(raiz->dir, v);
    }

    return raiz;
}

void imprimir_viloes_ordem(NoArvoreVilao* raiz) {
    if (raiz == NULL) return;
    imprimir_viloes_ordem(raiz->esq);
    printf("Vilao: %s | Nível: %d | Ponto Fraco: %s\n",
        nome_vilao(raiz->vilao),
        nivel_habilidade_vilao(raiz->vilao),
        ponto_fraco(raiz->vilao));
    imprimir_viloes_ordem(raiz->dir);
}

void liberar_arvore_vilao(NoArvoreVilao* raiz) {
    if (raiz == NULL) return;
    liberar_arvore_vilao(raiz->esq);
    liberar_arvore_vilao(raiz->dir);
    libera_vilao(raiz->vilao);
    free(raiz);
}
