#include <stdio.h>
#include <stdlib.h>

typedef struct noh_T{
    int item;
    struct noh_T *Prox;
}noh;

typedef struct{
    noh *topo;
    noh *fundo;
}pilha;

void CriaPilha (pilha *P){
    noh *aux;
    aux=malloc(sizeof(noh));
    aux->Prox=NULL;
    P->topo=aux;
    P->fundo=aux;
    //P->fundo->Prox=NULL;
}

int vazia(pilha *P){
    if (P->topo == P->fundo)
        return 1;
    else
        return 0;

    /* OU
    return P->topo == P->fundo;
    */
}

void empilha (int X, pilha *P){
    noh *aux;
    aux=malloc(sizeof(noh));
    aux->Prox=P->topo;
    P->topo->item=X;
    P->topo=aux;
}

void desempilha(pilha *P, int *X){
    if (vazia(P)){
        printf("Pilha Vazia.");
        return;
    }
    *X=P->topo->item;
    noh *aux=P->topo;
    P->topo=P->topo->Prox;
    aux->Prox=NULL;
    free(aux);
}

int Qtdade(pilha *P){
    noh *aux;
    int i=0;
    aux=P->topo;
    while (aux->Prox!=NULL){
        i++;
        aux=aux->Prox;
    }
    return i;
}

void ApagaPilha (pilha *P){
    noh *aux;
    aux=P->topo;
    while (aux->Prox!=NULL){
        P->topo=P->topo->Prox;
        aux->Prox=NULL;
        free(aux);
        aux=P->topo;
    }
    free(aux);
}

int main()
{
    pilha *P=malloc(sizeof(pilha));
    CriaPilha(P);
    int i=0;
    int X=0;

    while (i<10){
     empilha(i,P);
     i++;
    }

    i=0;
    while (i<10){
        desempilha(P, &X);
        printf("i=%d", X);
        i++;
    }
    return 0;
}
