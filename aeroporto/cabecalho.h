
#ifndef CABECALHO_H
#define CABECALHO_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct item tipoitem;//o que o aviao vai ter
typedef struct celula *apont;// apontador para celula
typedef struct fila *apontfila;//apontador para a fila
typedef struct celula celula;//conteudo da celula
typedef struct fila tipofila;// tudo que a fila precisa ter pra ser manipulada
void cria(tipofila *fila);//cria fila
int vazia(tipofila fila);//verifica se ela está vazia
void enfileira(tipofila *fila, tipoitem x);//adiona a fila sempre no ultimo
int desenfilera(tipofila *fila);//retira da fila, sempre o primeiro
void imprime(tipofila fila);//mostra fila
int busca(tipofila *fila, int *i);//busca avião com 1 de gasolina (de1 a 3)

int compara(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4);//compara o tanho das filas e retorna a menor
int maior(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4);//compara qual fila tem o menor combustivel para ser pousado
void removegasolina(tipofila *fila);//remove a gasolina dos avioes
int retiracaido(tipofila *fila, tipoitem *item);
void gerandoaviao(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4, tipoitem item, int id);
void decolar(int *pista, int tam, tipofila *decola,int *decolou, int *decoloutot,int *deciaDec );//decola os avioes
int decolagemAterrisagem(tipofila *f1, tipofila *f2, tipofila *f3, tipofila *f4, tipofila *decola, tipoitem *item, int *aterrisoutot, int *mediaAte,int *decoloutot,int *deciaDec);
//faz todo o controle de decolagem e Aterrisagem
#ifdef __cplusplus
}
#endif

#endif /* CABECALHO_H */

