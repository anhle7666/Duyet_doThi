#include <stdio.h>

typedef struct {
    int n, m;
    int A[20][20];
}Graph;

void init_graph(Graph *G, int n) {
    int i, j;
    G->n = n;
    for(i=1; i<=n; i++) 
        for(j = 1; j<=n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y) {
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}
//hang doi
typedef struct{
    int Data[100];
    int front, rear;
}Queue;

void make_null_Queue(Queue *Q) {
    Q->front = 0;
    Q->rear = -1;
}

void push(Queue *Q, int x) {
    Q->rear++;
    Q->Data[Q->rear] = x; 
}

int top(Queue *Q) {
    return Q->Data[Q->front];
}

void pop(Queue *Q){
    Q->front++;
}

//danh sach
typedef struct {
    int Data[100];
    int size;
}List;

void make_null_List(List *L) {
    L->size = 0;
}

void push_back(List *L, int x) {
    L->Data[L->size] = x;
    L->size++;
    
}

int element_at(List *L, int i) {
    return L->Data[i-1];
}

List neighbors(Graph *G, int x) {
    int i;
    List L;
    make_null_List(&L);
    for(i = 1; i<= G->n; i++) {
        if(G->A[x][i] != 0) push_back(&L, i);
    }
    return L;
}

void BFS(Graph *G) {
    Queue Q;
    int mark[100];
    make_null_Queue(&Q);

    int j;
    for(j = 1; j<= G->n; j++)
        mark[j] = 0;
    int i;
    for(i=1;i<=G->n;i++){
        if(mark[i]==1) // kiểm tra tính liên thông
        continue;
        push(&Q,i);
        mark[i]=1;
        while(!(Q.front > Q.rear)) {
            int x = top(&Q); pop(&Q);
            printf("%d\n", x);
    
            List L = neighbors(G,x);
    
            for(j = 1; j <= L.size; j++) {
                int y = element_at(&L, j);
                if(mark[y] == 0) {
                    mark[y] = 1;
                    push(&Q,y);
                }
            }
        }
    }
}

int main() {
    //freopen("dt.txt", "r", stdin);
    Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	BFS(&G);

}