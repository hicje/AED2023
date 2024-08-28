#include <stdio.h>
#include <stdlib.h>

typedef int tipoItem;

typedef struct no{
    
    tipoItem info;
    struct no* prox;
    struct no* ant;
}lista;

int vazia(lista* l){
    return l==NULL;
}

lista* inserir_cabeca(lista* l, tipoItem info){
    lista* aux = (lista*)malloc(sizeof(lista));
    aux->info = info;
    aux->ant = NULL;
    aux->prox = l;
    return aux;
}

void imprimir(lista* l){
    if(!vazia(l)){
        printf("%d ", l->info);
        imprimir(l->prox);
    }
}

lista* remover(lista*l, tipoItem info){
    lista* aux = l;
    lista* ant = l;
    if(vazia(l)){
        printf("erro\n");
        return l;
    }
    while((aux!=NULL)&&(aux->info!=info)){
        ant = aux;
        aux = aux->prox;
    }
    
    if(aux == l){
        l = l->prox;
        free(aux);
        return l;
    }else if(aux->info == info){
        ant->prox = aux->prox;
        ant->ant = aux->ant;
        free(aux);
        return l;
    }else{
        printf("Elemento nao encontrado\n");
        return l;
    }
}

lista* inserir_apos(lista* l, tipoItem x, tipoItem info){
    lista* aux = l;
    lista* ant = l;
    if(vazia(l)){
        l=inserir_cabeca(l,info);
        return l;
    }
    while((aux!=NULL)&&(aux->info == x)){
        ant = aux;
        aux = aux->prox;
    }
    if(aux->info == x){
        lista* new = (lista*)malloc(sizeof(lista));
        new->info = info;
        new->prox = aux->prox;
        new->ant = aux;
        aux ->prox = new;
        ant = new->prox;
        ant->ant = new;
        return l;
    }else{
        printf("nao encontrado\n");
        return l;
    }
}

int main(){
    lista* l = NULL;
    l = inserir_cabeca(l, 5);
    l = inserir_cabeca(l, 4);
    l= inserir_cabeca(l, 7);
    imprimir(l);
    printf("\n");
    l = remover(l, 4);
    imprimir(l);
    printf("\n");
    l - inserir_apos(l,4,7);
    imprimir(l);
    printf("\n");
    return 0;
}
