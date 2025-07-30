#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define TAM 200

typedef struct no_pilha {
    char mensagem[TAM];
    struct no_pilha* prox;
} NoPilha;

struct pilha {
    NoPilha* topo;
};

Pilha* criar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) p->topo = NULL;
    return p;
}

void empilhar(Pilha* p, const char* mensagem) {
    if (p == NULL) return;
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo == NULL) return;
    strncpy(novo->mensagem, mensagem, TAM - 1);
    novo->mensagem[TAM - 1] = '\0';
    novo->prox = p->topo;
    p->topo = novo;
}

void imprimir_pilha(Pilha* p) {
    if (p == NULL) return;
    NoPilha* atual = p->topo;
    while (atual != NULL) {
        printf("%s\n", atual->mensagem);
        atual = atual->prox;
    }
}

void liberar_pilha(Pilha* p) {
    if (p == NULL) return;
    NoPilha* atual = p->topo;
    while (atual != NULL) {
        NoPilha* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(p);
}
