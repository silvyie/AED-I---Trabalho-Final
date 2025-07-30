#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tartaruga.h"

#define TAM 50

struct tartaruga {
    char nome[TAM];
    StatusTartaruga status;
    int nivel;
};

Tartaruga *cria_tartaruga(const char *nome, StatusTartaruga status, int nivel){
    Tartaruga *nova_tartaruga =  (Tartaruga*)malloc(sizeof(Tartaruga));

    if(nova_tartaruga == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    strncpy(nova_tartaruga->nome, nome, sizeof(nova_tartaruga->nome) -1);
    nova_tartaruga->nome[sizeof(nova_tartaruga->nome) -1] = '\0';
    nova_tartaruga->status = status;
    nova_tartaruga->nivel = nivel;

    return nova_tartaruga;
}

char *nome_tartaruga(Tartaruga *t){
    if(t == NULL){
        return NULL;
    }

    return t->nome;
}

StatusTartaruga status_tartaruga(Tartaruga *t){
    if(t == NULL){
        return DISPONIVEL;
    }

    return t->status;
}

int nivel_tartaruga(Tartaruga *t){
    if(t == NULL){
        return 1;
    }
    return t->nivel;
}

void modifica_status(Tartaruga* t, StatusTartaruga novo_status_tartaruga){
    if(t != NULL){
        t->status = novo_status_tartaruga;
    }
}

void modifica_nivel(Tartaruga *t, int novo_nivel_tartaruga){
    if (t != NULL && novo_nivel_tartaruga >= 1 && novo_nivel_tartaruga <= 10) {
        t->nivel = novo_nivel_tartaruga;
    }
}

void aumenta_nivel(Tartaruga* t, int incremento){
    if(t != NULL){
        t->nivel += incremento;

        if(t->nivel > 10){
            t->nivel = 10;
        }else if(t->nivel < 1){
            t->nivel = 1;
        }
    }
}

void libera_tartaruga(Tartaruga* t){
    if(t != NULL){
        free(t);
    }
}