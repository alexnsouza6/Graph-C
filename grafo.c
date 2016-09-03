#include <stdio.h>
#include <stdlib.h>
#include "FUNC.h"
#include <sys/time.h>


void ImprimeGrafo(grafo *gr, int n)
{
    int i,j;

    for(i=0; i<n; i++)
    {
        Edge *aux = gr->v[i].list;
        j=0;
        do
        {
            printf("Vertice adjacente a %d: ", i);
            printf("%d\n", aux->vdestino);
            printf("Peso da aresta que conecta %d a %d: ", i,aux->vdestino);
            printf("%d\n", aux->peso);
            if(aux->prox != NULL)aux = aux->prox;
            else j=1;
        }
        while(j!=1);
    }
}

grafo* criaGrafo(int n)
{
    int i;
    grafo* gr=(grafo*) malloc(sizeof(struct grafo));
    if(gr!=NULL)
    {
        gr->nvertices = n; 
        gr->v = (Vertex*)malloc(n*sizeof(Vertex)); //vetor de vertices
        for(i=0; i<n; i++)
            gr->v[i].list = inicializa(); // cria a lista de adjacencia para cada vertice
    }
    return gr;
}
grafo* criaAresta(grafo *G, int origem, int destino, int p)
{

    G->v[origem].list = Insere(G->v[origem].list,destino,p);
    G->v[destino].list = Insere(G->v[destino].list,origem,p);
    /* Como o grafo eh nao direcionado temos que adicionar o vertice em dois sentidos, ou seja, i->j e j->i */

    return G;

}
Edge* Insere(Edge* e, int destino, int peso)
{
    Edge* novo = (Edge *)malloc(sizeof(Edge));
    novo->peso = peso; //o peso eh atribuido a nova aresta inserida. O mesmo ocorre para o seu destino
    novo->vdestino = destino;
    novo->prox = e;
    return novo;
}
Edge* inicializa(void)
{
    return NULL;
}