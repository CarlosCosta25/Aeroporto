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

/*------------------------------------------------------ARQUIVO PRINCIPAL---------------------------------------*/
int main(int argc, char** argv) {
    tipofila f1, f2, f3, f4, decola;
    tipoitem item;
    int op , i=0, j;
    int id_ater = 0, id_dec = 1;
    int caiutot =0, caiu = 0;//controle de avioes que caiu
    int mediaAte =0, deciaDec = 0, aterrisoutot = 0,decoloutot = 0;
    int gerado; //quantidade de avioes que vão chegar na fila pra decolar ou pousar
    srand(time(NULL));
    cria(&f1);
    cria(&f2);
    cria(&f3);
    cria(&f4);
    cria(&decola);
    printf("Digite quantas unidades de tempo você deseja simular: ");
    scanf("%d", &op);
    while(i< op){
        i++;
        printf("\n--------------------------UNIDADE DE TEMPO: %d--------------------", i);
        gerado = rand() % 4;
        printf("\nAo todo %d avioes chegaram no aeroporto para aterrissar", gerado);
        printf("\n----------------CHEGADA DE AVIOES NA FILA DE ATERRISSAGEM----------------\n");
        for (j = 0; j < gerado; j++) {
            id_ater = id_ater + 2;
            gerandoaviao(&f1, &f2, &f3, &f4, item, id_ater);
        }
        //gerando a quantidade de avioes que vão ser inseridos na fila de decolagem
        gerado = rand() % 4;
        printf("\n----------------CHEGADA DE AVIOES NA FILA DE DECOLAGEM----------------\n");
        printf("\n Ao total, %d aviões estão na fila de espera para decolar!\n", gerado);
        for (j = 0; j < gerado; j++) {
            item.gasolina = 20;//gerqndo os atributos do aviao
            id_dec = id_dec + 2;
            item.id = id_dec;
            enfileira(&decola, item);
        }
        printf("\nAvioes fila  de decolagem:");
        imprime(decola);

        printf("\n-----------------DECOLAGEM OU ATERRISAGEM DOS AVIÕES-----------------\n");
        //aqui faz todo o controle de descida de decolagem
           caiu =decolagemAterrisagem(&f1, &f2, &f3, &f4, &decola, &item,&aterrisoutot,&mediaAte,&decoloutot,&deciaDec);
           aterrisoutot = caiu+ caiutot;
           
           
        float resultAte =0; 
        resultAte= (float)aterrisoutot/(float)mediaAte;//calcula o tempo media de aterrisagem
        float resultDec =0;
        resultDec =(float)decoloutot/(float)deciaDec;//calcula o tempo media de decolagem
        
        
        printf("\n----------REMOVENDO GASOLINA DOS AVIÕES---------------------------------------\n");
        //remove gasolina de todos os avioes
        printf("fila 1: ");
        removegasolina(&f1);
        printf("fila 2: ");
        removegasolina(&f2);
        printf("fila 3: ");
        removegasolina(&f3);
        printf("fila 4: ");
        removegasolina(&f4);
        printf("fila de decolagem: ");
        removegasolina(&decola);


        printf("\n===========RESUMO DO CICLO===========================\n");
        printf("\nAviões que cairam: %d", caiutot);
        printf("\nO TEMPO MEDIO DE ATERRISAGEM: %f CICLOS",resultAte);
        printf("\nO TEMPO MEDIO DE DECOLAGEM: %f CICLOS",resultDec);
        printf("\nA quantidade de avioes que aterrissaram: %d",mediaAte);
           printf("\nA quantidade de avioes que decolaram: %d\n",deciaDec);
        printf("\nTAMANHO DAS FILAS:");
        printf("\nFila 1: %d avioes na espera\n Fila 2: %d avioes na espera\n Fila 3: %d avioes na espera\n Fila 4: %d avioes na espera\n DECOLAGEM: %d avioes na espera\n", f1.tam, f2.tam, f3.tam, f4.tam, decola.tam);
        printf("\nCONTEUDO DAS FILAS:");
        printf("\nAvioes fila 1:");
        imprime(f1);
        printf("\nAvioes fila 2:");
        imprime(f2);
        printf("\nAvioes fila 3:");
        imprime(f3);
        printf("\nAvioes fila 4:");
        imprime(f4);
        printf("\nAvioes fila decolagem:");
        imprime(decola);
        printf("\n=================================================================\n");
        //printf("\n========DIGITE 1 PARA IR AO PROXIMO CICLO========================\n");
        //int proximo;
        //scanf("%d", &proximo);
    }

    return (EXIT_SUCCESS);
}



