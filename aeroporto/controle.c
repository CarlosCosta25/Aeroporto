#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cabecalho.h"
#define ocupado 1
#define vazio 0

typedef struct item {
    int id;
    int gasolina;
    int gasoIni; //gasolina no qual o avião chegou na fila de espera
} tipoitem;
typedef struct celula *apont;
typedef struct fila *apontfila;

typedef struct celula {
    tipoitem aviao;
    apont prox;
} celula;

typedef struct fila {
    apont frente, tras;
    int tam;
} tipofila;


void gerandoaviao(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4, tipoitem item, int id) {
    //gera avioes para as listas de decolagem e faz o controle de em qual fila inserir
    int conf;
    //gera os atributos do aviao
    item.gasolina = 1 + (rand() % 20);
    item.id = id;
    printf("\n%d gasolina", item.gasolina);
    printf("\n%d id\n", item.id);
    conf = compara(f1, f2, f3, f4);
    //verificando em qual lista o aviao vai ser inserido
    if (conf == 1) {
        enfileira(f1, item);
        printf("\nAvioes fila 1:");
        imprime(*f1);
    } else {
        if (conf == 2) {
            enfileira(f2, item);
            printf("\nAvioes fila 2:");
            imprime(*f2);
        } else {
            if (conf == 3) {
                enfileira(f3, item);
                printf("\nAvioes fila 3:");
                imprime(*f3);
            } else {
                if (conf == 4) {
                    enfileira(f4, item);
                    printf("\nAvioes fila 4:");
                    imprime(*f4);
                }
            }
        }
    }
}

int decolagemAterrisagem(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4, tipofila *decola, tipoitem *item, int *aterrisoutot, int *mediaAte,int *decoloutot,int *deciaDec) {
    //função que faz o controle de todas as descidas e decolagens dos avioes.
    int caiu = 0, aterrissou =0, decolou = 0, caiutot =0; //valor total de avioes que cairam
    int j;
    int pista[3] = {vazio, vazio, vazio};//essa e a pista para o controle da aterrissagem e decolagem
    printf("->VERIFICANDO SE ALGUM AVIÃO CAIU: ");
    printf("\nFila 1:");
    caiu = retiracaido(f1, item);
    caiutot = caiu + caiutot;
    printf("\nFila 2:");
    caiu = retiracaido(f2, item);
    caiutot = caiu + caiutot;
    printf("\nFila 3:");
    caiu = retiracaido(f3, item);
    caiutot = caiu + caiutot;
    printf("\nFila 4:");
    caiu = retiracaido(f4, item);
    caiutot = caiu + caiutot;
    // busca avião que está proximo de cair
    int posi = 0;
    for (int r = 0; r < 3; r++) {
        if (pista[r] == vazio && busca(f1, &posi) == 1) {
            printf("\n Um avião está proximo de cair!, e sua posição na fila é: %d", posi);
            int q;
            for (q = 0; q < posi; q++) {
                if (pista[q] == vazio) {
                    pista[q] = ocupado;
                    aterrissou = desenfilera(f1);
                    *aterrisoutot = *aterrisoutot + aterrissou;
                    *mediaAte =*mediaAte + 1;//quantidade de avioes que aterrisaram
                }
            }
        }
        if (pista[r] == vazio && busca(f2, &posi) == 1){
            printf("\n Um avião está proximo de cair!, e sua posição na fila é: %d", posi);
            int q;
            for (q = 0; q < posi; q++) {
                if (pista[q] == vazio) {
                    pista[q]= ocupado;
                    aterrissou = desenfilera(f2);
                    *aterrisoutot = *aterrisoutot + aterrissou;
                    *mediaAte=*mediaAte +1;
                }
            }
        }
        if (pista[r] == vazio && busca(f3, &posi) == 1) {
            printf("\n Um avião está proximo de cair!, e sua posição na fila é: %d", posi);
            int q;
            for (q = 0; q < posi; q++) {
                if (pista[q] == vazio) {
                    pista[q]= ocupado;
                    aterrissou = desenfilera(f3);
                    *aterrisoutot = *aterrisoutot + aterrissou;
                    *mediaAte =*mediaAte +1;
                }
            }
        }
        if (pista[r] == vazio && busca(f4, &posi) == 1) {
            printf("\n Um avião está proximo de cair!, e sua posição na fila é: %d", posi);
            int q;
            for (q = 0; q < posi; q++) {
                if (pista[q] == vazio) {
                    pista[q] = ocupado;
                    aterrissou = desenfilera(f4);
                    *aterrisoutot = *aterrisoutot + aterrissou;
                    *mediaAte = *mediaAte +1;
                }
            }
        }
    }
    printf("\nATERRISAGEM DE AVIÕES:\n");
    for (j = 0; j < 2; j++) {
        if (pista[j] == vazio) {
            int comp;
            comp = maior(f1, f2, f3, f4);// retorna a fila maior
            if (comp == 1) {
                if (f1->tam != 0) {//se acaso a fila 1 estiver vazia, ele n entra nessa condição,
                    //isso aconte pq se acaso todas as pistas forem de tamanho iguais, a fila 1 que será retornada
                    printf("\nUm avião da fila 1 aterrissou\n");
                    pista[j] = ocupado;
                    aterrissou = desenfilera(f1);
                    *aterrisoutot = *aterrisoutot + aterrissou;
                    *mediaAte= *mediaAte+ 1;
                }
            }
            if (comp == 2) {
                printf("\nUm avião da fila 2 aterrissou\n");
                pista[j] = ocupado;
                aterrissou = desenfilera(f2);
                *aterrisoutot = *aterrisoutot + aterrissou;
                *mediaAte= *mediaAte+ 1;
            }
            if (comp == 3) {
                printf("\nUm avião da fila 3 aterrissou\n");
                pista[j] = ocupado;
                aterrissou = desenfilera(f3);
                *aterrisoutot = *aterrisoutot + aterrissou;
                *mediaAte= *mediaAte+ 1;
            }
            if (comp == 4) {
                printf("\nUm avião da fila 4 aterrissou\n");
                pista[j]= ocupado;
                aterrissou = desenfilera(f4);
                *aterrisoutot = *aterrisoutot + aterrissou;
                *mediaAte= *mediaAte+ 1;
            }
        }
    }
    printf("\nDECOLAGEM DE AVIÕES:\n");
    decolar(&pista,3,decola,&decolou,decoloutot,deciaDec);
    
    //aqui se acaso a pista de decolagem estiver sem aviões, um avião será decolado
    for (j = 0; j < 3; j++) {
        if (pista[j] == vazio) {
            int comp;
            comp = maior(f1, f2, f3, f4);
            if (comp == 1) {
                if (f1->tam != 0) {//se acaso a fila 1 estiver vazia, ele n entra nessa condição,
                    //isso aconte pq se acaso todas as pistas forem de tamanho iguais, a fila 1 que será retornada
                    printf("\nUm avião da fila 1 aterrissou\n");
                    pista[j] = ocupado;
                    aterrissou = desenfilera(f1);
                    printf("\nAterrisou em %d ciclo\n", aterrissou);
                    *aterrisoutot = *aterrisoutot + aterrissou;
                    *mediaAte= *mediaAte+ 1;
                }
            }
            if (comp == 2) {
                printf("\nUm avião da fila 2 aterrissou\n");
                pista[j] = ocupado;
                aterrissou = desenfilera(f2);
                *aterrisoutot = *aterrisoutot + aterrissou;
                printf("\nAterrisou em %d ciclo\n", aterrissou);
                *mediaAte= *mediaAte+ 1;
            }
            if (comp == 3) {
                printf("\nUm avião da fila 3 aterrissou\n");
                pista[j] = ocupado;
                aterrissou = desenfilera(f3);
                *aterrisoutot = *aterrisoutot + aterrissou;
                printf("\nAterrisou em %d ciclo\n", aterrissou);
                *mediaAte= *mediaAte+ 1;
            }
            if (comp == 4) {
                printf("\nUm avião da fila 4 aterrissou\n");
                pista[j] = ocupado;
                aterrissou = desenfilera(f4);
                *aterrisoutot = *aterrisoutot + aterrissou;
                printf("\nAterrisou em %d ciclo\n", aterrissou);
                *mediaAte= *mediaAte+ 1;
            }
        }
    }
    return caiutot;
}




