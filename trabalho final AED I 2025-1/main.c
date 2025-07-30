#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tartaruga.h"
#include "vilao.h"
#include "arsenal.h"
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "arvore_vilao.h"
#include "missao.h"

// Estruturas principais
Lista *lista_tartarugas = NULL;
NoArvoreVilao *arvore_viloes = NULL;
FilaArsenal *arsenal = NULL;
Pilha *diario_bordo = NULL;
NoMissao *fila_missoes = NULL;

void menu_tartaruga() {
    char nome[50];
    int nivel;
    printf("\nNome da tartaruga: ");
    scanf(" %[^\n]", nome);
    printf("Nivel (1 a 10): ");
    scanf("%d", &nivel);

    Tartaruga *t = cria_tartaruga(nome, DISPONIVEL, nivel);
    lista_tartarugas = insere_final(lista_tartarugas, t);

    printf("Tartaruga adicionada!\n");
}

void menu_vilao() {
    char nome[50], ponto[50];
    int nivel;
    printf("\nNome do vilao: ");
    scanf(" %[^\n]", nome);
    printf("Nivel habilidade (1 a 10): ");
    scanf("%d", &nivel);
    printf("Ponto fraco: ");
    scanf(" %[^\n]", ponto);

    Vilao *v = cria_vilao(nome, nivel, ponto);
    arvore_viloes = inserir_vilao(arvore_viloes, v);

    printf("Vilao adicionado!\n");
}

void menu_arsenal() {
    char nome[50];
    int custo, atk, def, tipo;
    printf("\nNome do equipamento: ");
    scanf(" %[^\n]", nome);
    printf("Custo: ");
    scanf("%d", &custo);
    printf("Bonus ataque: ");
    scanf("%d", &atk);
    printf("Bonus defesa: ");
    scanf("%d", &def);
    printf("Tipo (0-Arma, 1-Armadura, 2-Cura): ");
    scanf("%d", &tipo);

    Equipamento *e = cria_equipamento(nome, custo, atk, def, tipo);
    enfileirar(arsenal, e);

    printf("Equipamento adicionado!\n");
}

void menu_missao() {
    char desc[100], local[100];
    int nivel, recompensa;
    printf("\nDescricao: ");
    scanf(" %[^\n]", desc);
    printf("Local: ");
    scanf(" %[^\n]", local);
    printf("Nivel de ameaca (1 a 10): ");
    scanf("%d", &nivel);
    printf("Recompensa: ");
    scanf("%d", &recompensa);

    Missao *m = cria_missao(desc, local, ATIVA, nivel, recompensa);
    fila_missoes = inserir_missao_prioridade(fila_missoes, m);

    printf("Missao adicionada à fila!\n");
}

void menu_iniciar_missao() {
    if (fila_missoes == NULL) {
        printf("\nNenhuma missão disponível.\n");
        return;
    }

    printf("\nIniciando missão...\n");
    printf("Missão: %s (%s)\n", descricao_missao(fila_missoes->dados), local_missao(fila_missoes->dados));

    empilhar(diario_bordo, descricao_missao(fila_missoes->dados));
    fila_missoes = remover_missao(fila_missoes);

    printf("Missao registrada no diario de bordo e removida da fila.\n");
}

void menu_diario() {
    printf("\n=== Diario de Bordo ===\n");
    imprimir_pilha(diario_bordo);
}

void imprimir_opcoes() {
    printf("\n=== CENTRAL DE COMANDO ===\n");
    printf("1 - Adicionar Tartaruga\n");
    printf("2 - Adicionar Vilao\n");
    printf("3 - Adicionar Missao\n");
    printf("4 - Adicionar Equipamento ao Arsenal\n");
    printf("5 - Iniciar Missao\n");
    printf("6 - Consultar Diario de Bordo\n");
    printf("7 - Listar Tartarugas\n");
    printf("8 - Listar Viloes (em ordem)\n");
    printf("9 - Listar Arsenal\n");
    printf("10 - Listar Missoes Pendentes\n");
    printf("0 - Sair\n");
}

int main() {
    int opcao;

    lista_tartarugas = cria_lista();
    arsenal = criar_fila();
    diario_bordo = criar_pilha();

    do {
        imprimir_opcoes();
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menu_tartaruga(); break;
            case 2: menu_vilao(); break;
            case 3: menu_missao(); break;
            case 4: menu_arsenal(); break;
            case 5: menu_iniciar_missao(); break;
            case 6: menu_diario(); break;
            case 7: imprime_lista(lista_tartarugas, (void (*)(void*))nome_tartaruga); break;
            case 8: imprimir_viloes_ordem(arvore_viloes); break;
            case 9: imprimir_fila(arsenal); break;
            case 10: imprimir_fila_missoes(fila_missoes); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    libera_lista(lista_tartarugas, (void (*)(void*))libera_tartaruga);
    liberar_arvore_vilao(arvore_viloes);
    liberar_fila(arsenal);
    liberar_pilha(diario_bordo);
    liberar_fila_missoes(fila_missoes);

    return 0;
}