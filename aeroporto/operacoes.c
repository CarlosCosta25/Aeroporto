#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cabecalho.h"
#define ocupado 1
#define vazio 0
typedef struct item{
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

void cria(tipofila *fila) {//cria uma celula cabeca
    fila->frente = (apont) malloc(sizeof (celula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL;
    fila->tam = 0;
}

int vazia(tipofila fila) {
    return (fila.frente == fila.tras);//verifica se está fazia
}

void enfileira(tipofila *fila, tipoitem x) {//enfilera sempre no fim
    fila->tras->prox = (apont) malloc(sizeof (celula));
    fila->tras = fila->tras->prox;
    fila->tras->aviao.gasolina = x.gasolina;
    fila->tras->aviao.id = x.id;
    fila->tras->aviao.gasoIni = x.gasolina;
    fila->tras->prox = NULL;
    fila->tam++;
}

int desenfilera(tipofila *fila) {//desenfilera sempre da primeira posição
    apont aux;
    int conf = 0;
    if (vazia(*fila)) {
        printf("\nA fila está vazia\n");
    }
    aux = fila->frente->prox;
    fila->frente->prox = aux->prox;

    if (aux->prox == fila->tras->prox) {
        fila->tras = fila->frente;//aqui e pra não perder a referencia do ultimo, isso estava acontecendo muito
    }
    conf = aux->aviao.gasoIni - aux->aviao.gasolina;
    free(aux);
    fila->tam--;
    return conf;
}

void imprime(tipofila fila) {
    if (fila.tam != 0) {
        apont aux;
        aux = fila.frente->prox;
        while (aux != NULL) {
            printf("\nid: %d, gasolina: %d\n", aux->aviao.id, aux->aviao.gasolina);
            aux = aux->prox;

        }
    } else {
        printf("fila vazia");
    }
}

int busca(tipofila *fila, int *i) {
    //busca sempre as primeiras posições
    int cont = 0;
    if (fila->frente->prox == NULL) {
        cont = cont;
        return cont;
    } else {
        apont aux;
        aux = fila->frente;
        while (aux->prox != NULL && aux->prox->aviao.gasolina != 1 && *i != 3) {
            aux = aux->prox;
            *i++;
        }
        if (aux->prox == NULL || *i == 3) {
            cont = 0;
            return cont;
        } else {
            cont = 1;
            return cont;
        }
    }
}
int compara(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4) {//compara o tamnho das filas
    apontfila aux = f1; //sempre começa na fila 1, e se todas for fazia e nele que vai adicionar de primeira
    int cont = 1;

    if (aux->tam > f2->tam) {
        aux = f2;
        cont = 2;
    }
    if (aux->tam > f3->tam) {
        aux = f3;
        cont = 3;
    }
    if (aux->tam > f4->tam) {
        aux = f4;
        cont = 4;
    }
    return cont;
}

int maior(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4) {//compara qual fila tem o menor combustivel para ser pousado
    apontfila aux = f1;//sempre começa na fila 1, e se todas for fazia e ele que vai ser o menor, cuidado ao usar
    int cont = 1;

    if (aux->tam < f2->tam) {
        aux = f2;
        cont = 2;
    }
    if (aux->tam < f3->tam) {
        aux = f3;
        cont = 3;
    }
    if (aux->tam < f4->tam) {
        aux = f4;
        cont = 4;
    }
    return cont;
}

void removegasolina(tipofila *fila) {//remove a gasolina dos avioes
    if (vazia(*fila)) {
        printf("Fila vazia\n");
    } else {
        apont aux;
        aux = fila->frente->prox;
        while (aux != NULL) {
            aux->aviao.gasolina = aux->aviao.gasolina - 1;
            printf("gasolina: %d\n", aux->aviao.gasolina);
            aux = aux->prox;
        }
    }
}
int retiracaido(tipofila *fila, tipoitem *item) {
    //função que remove os avioes que já cairam e também mostra ao usurio se tem algum aviao que caiu, está proximo de cair, ou não.
    int cont = 0;
    if (fila->frente->prox == NULL){
        printf("A fila está vazia!\n");
        return cont;
    } else {
        apont aux;
        aux = fila->frente;
        apont q;
        while ((aux->prox != NULL) && (aux->prox->aviao.gasolina != 0)){
            aux = aux->prox;//busca se algum aviao está sem gasolina
        }
        if (aux->prox == NULL){
            printf("Nenhum avião está proximo de cair nessa fila\n");
            return cont;
        }
        if(aux->aviao.gasolina == 0){
            printf("\n###############\n");//mostra que um aviao caiu
            printf("# AVIÃO CAIU! #");
            printf("\n###############\n");
            q = aux->prox;
        if (fila->tras->prox == q->prox) {
            fila->tras = aux;
        }
        aux->prox = q->prox;
        *item = q->aviao;//faz a retirada dele
        free(q);
        fila->tam--;
        cont = 1;
        return cont;
        }
    }
}
void decolar(int *pista,int tam, tipofila *decola,int *decolou, int *decoloutot,int *deciaDec ){
    int j;
    for (j = 2; j>-1; j--) {
        if (pista[j]== vazio) {//verifica se a pista está vazia
            if (decola->tam != 0) {//verifica se ela está vazia
                printf("\nUm avião decolou!");
                pista[j]= ocupado;
                *decolou = desenfilera(decola);
                *decoloutot = *decolou + *decoloutot;
                *deciaDec = *deciaDec +1;//calcula a quantidade de avioes que decolaram
            }
        }
    }   
}