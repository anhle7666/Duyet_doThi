#include <stdio.h>
#define MAX_VERTEXES 100
#define MAX_ELEMENTS 100
#define MAX_NODES 100
/* Khai bao Stack*/
typedef struct {
	int data[MAX_ELEMENTS];
	int size;
} Stack;
void make_null_stack(Stack* S) {
	S->size = 0;
}
void push(Stack* S, int x) {
	S->data[S->size] = x;
	S->size++;
}
int top(Stack* S) {
	return S->data[S->size - 1];
}
void pop(Stack* S) {
	S->size--;
}
int empty(Stack* S) {
	return S->size == 0;
}
// khi bao do thi
typedef struct {
	int n, m;
	int A[MAX_VERTEXES][MAX_VERTEXES];
}Graph;
// khoi tao do thi
void init_graph (Graph *G, int n) {
	int i, j;
	G->n = n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			G->A[i][j] = 0;
}
// them cung
void add_edge (Graph *G, int x, int y) {
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}
// kiem tra co ke
int adjacent (Graph *G, int x, int y) {
	return G->A[x][y] != 0;
}
// khai bao danh sach
typedef int ElementType;
typedef struct {
	ElementType data [MAX_ELEMENTS];
	int size;
}List;
// tao rong
void make_null(List * L) {
	L->size = 0;
}
// them phan tu
void push_back(List *L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
// lay phan tu tai vi tri i, phan tu dat o bat ky dau
ElementType element_at(List * L, int i) {
	return L->data[i-1];
}
// tra ve so phan tu danh sach
int count_list(List *L) {
	return L->size;
}
// tim cac dinh ke
List neighbors (Graph * G, int x) {
	int y;
	List list;
	make_null(&list);
	for (y = 1; y <= G->n; y++)
		if (adjacent(G, x, y))
			push_back(&list, y);
	return list;
}
int mark[MAX_VERTEXES];
/* Duyet do thi theo chieu sau */
void depth_first_search(Graph* G, int x) {
	Stack frontier;
//int mark[MAX_VERTEXES];
//int duyet[MAX_NODES];
	make_null_stack(&frontier);
/* Khoi tao mark, chua dinh n�o duoc x�t */
	int j;
//int i;
	for (j = 1; j <= G->n; j++)
//mark[j] = 0;
/* �ua 1 v�o frontier */
	push(&frontier, x);
/* Vong lap chinh dung de duyet */
	while (!empty(&frontier)) {
/* Lay phan tu dau ti�n trong frontier ra */
		int x = top(&frontier); pop(&frontier);
		if (mark[x] != 0)
			continue;	
		printf("%d\n", x);
		mark[x] = 1; //��nh d?u n� d� duy?t
/* L?y c�c d?nh k? c?a n� */
		List list = neighbors(G, x);
/* X�t c�c d?nh k? c?a n� */
		for (j = 1; j <= list.size; j++) {
			int y = element_at(&list, j);
				push(&frontier, y);
		}
	}
}
int main () {
	freopen("dt.txt", "r", stdin);
	Graph G;
int n, m, u, v, w, e, x;
scanf("%d%d", &n, &m);
init_graph(&G, n);
for (e = 0; e < m; e++) {
scanf("%d%d", &u, &v);
add_edge(&G, u, v);
//depth_first_search(&G);
}
depth_first_search(&G, 1);
for (w = 1; w <= n; w++)
if (mark[w] == 0)
depth_first_search(&G, w);
return 0;
}
