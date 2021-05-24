#include <stdio.h>
typedef struct {
    int A[20][20];
    int n, m;
}Graph;

void init_graph(Graph *G, int n) {
    G->n = n;
    int i,j;
    for(i = 1; i <= n; i++) 
        for(j=1; j<=n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y) {
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

typedef struct {
    int Data[100];
    int size;
}List;

void make_nul(List *L) {
    L->size = 0;
}

void push_back(List *L, int x) {
    L->Data[L->size] = x;;
    L->size++;
}

int element_at(List *L, int i) {
    return L->Data[i-1];
}

List neighbors(Graph *G, int x) {
    int i;
    List L;
    make_nul(&L);
    for(i=1; i<=G->n; i++) 
        if(G->A[x][i] == 1)
            push_back(&L, i);
    return L;
}

int mark[100];

void traversal(Graph *G, int x) {
    if(mark[x] == 1) return;
    printf("%d \n", x);
    mark[x] = 1;

    List L = neighbors(G,x);
    int j;
    for(j = 1; j <= L.size; j++) {
        int y = element_at(&L, j);
        traversal(G,y);
    }
}

void DFS(Graph *G) {
    int j,i;
    for(j=1; j<=G->n; j++) 
            traversal(G,1);
    for(i=1; i<=G->n; i++)
        if(mark[i] == 0) traversal(G,i);
}

int main() {
    Graph G;
    int n,m,e,u,v;
    scanf("%d%d", &n,&m);
    init_graph(&G,n);

    for(e = 0; e<G.n; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u,v);
    }
    DFS(&G);
}