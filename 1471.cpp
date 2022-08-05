#include <iostream>
using namespace std;

int ft[150001], visbl[150001], dist[150001], result[75001][3];

typedef struct node{
    int v, d; //tree structure consist of nodes
    struct node *nxt;//next node of tree
} NODE;

NODE *conn_1[150001], *conn_2[150001], edge_1[300001], edge_2[300001];

void Add_new_node(int u, int v, int w, NODE *edge, NODE **conn, int &idx){//to move all nodes and ann new one from input
    edge[idx].v = v, edge[idx].d = w;
    edge[idx].nxt = conn[u];
    conn[u] = edge + idx++;
    edge[idx].v = u, edge[idx].d = w;
    edge[idx].nxt = conn[v];
    conn[v] = edge + idx++;
}

int find_prnt(int x){//to check parent node in tree by idx
    if (x != ft[x]) return ft[x] = find_prnt(ft[x]);
    return x;
}

void DFS(int u){//deep first search
    visbl[u] = 1;
    ft[u] = u;
    NODE *p;
    for (p = conn_2[u]; p; p = p->nxt) if (visbl[p->v]) result[p->d][2] = find_prnt(p->v);
    for (p = conn_1[u]; p; p = p->nxt){
        if (!visbl[p->v]){
            dist[p->v] = dist[u] + p->d;
            DFS(p->v);
            ft[p->v] = u;
        }
    }
}

int main() {
    int N, M, i, u, v, w, idx1 = 0, idx2 = 0;
	//input
    cin>>N;
    memset(conn_1, 0, sizeof conn_1);
    for (i = 0; i < N-1; i++){
        cin >> u >> v >> w;
        Add_new_node(u, v, w, edge_1, conn_1, idx1);
    }
	//queries
    cin>>M;
    memset(conn_2, 0, sizeof conn_2);
    for (i = 0; i < M; i++){
        cin>>u>>v;
        Add_new_node(u, v, i, edge_2, conn_2, idx2);
        result[i][0] = u;
        result[i][1] = v;
    }
    memset(visbl, 0, sizeof visbl);
    dist[1] = 0;
    DFS(1);
	//output
    for (i = 0; i < M; i++)
        cout << dist[result[i][0]] + dist[result[i][1]] - 2 * dist[result[i][2]]<<endl;
    return 0;
}