#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* criar_pilha();
void empilhar(Pilha* p, const char* mensagem);
void imprimir_pilha(Pilha* p);
void liberar_pilha(Pilha* p);

#endif
