typedef struct grafo grafo;
typedef struct vertex Vertex;
typedef struct edge Edge;


struct edge
{
    int vdestino;   //vertice destino da aresta
    int peso;       //peso de cada de vertice
    Edge *prox;
};
struct vertex
{
    Edge *list; //ponteiro para lista de arestas
    int cor; // O = BRANCO(nao visitado), 1 = CINZA(visitado), 2 = PRETO(explorado);
    int dorigem; // distancia da origem
    int definitivo; // ponteiro para os vertices que compoe o caminho principal
    int pparcial; // peso de cada caminho parcial
};
struct grafo
{
    int nvertices; //numero de vertices
    Vertex *v; // vetor de vertices
    
};
grafo* criaGrafo(int n);
grafo* criaAresta(grafo *G, int origem, int destino, int p);
Edge* Insere(Edge* e, int destino, int peso);
Edge* inicializa(void);
void ImprimeGrafo(grafo *G, int n);
