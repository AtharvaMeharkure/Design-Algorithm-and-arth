#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int find(int parent[], int i) {
   if (parent[i] == i)
return i;
return find(parent, parent[i]);


}


void union1(int parent[], int rank[], int i, int j) {
int ri = find(parent, i);
int rj = find(parent, j);

if (rank[ri] < rank[rj]) {
parent[ri] = rj;
} else if (rank[ri] > rank[rj]) {
parent[rj] = ri;
} else {
parent[rj] = ri;
rank[ri]++;
}



}


void kruskalMST(int **cost, int V) {// Write your code here...
int parent[V], rank[V];
for (int i = 0; i < V; i++) {
parent[i] = i;
rank[i] = 0;
}

int edgeCount = 0, minCost = 0;

while (edgeCount < V - 1) {
int min = INT_MAX, u = -1, v = -1;

// Find the smallest edge that doesn’t form a cycle
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (find(parent, i) != find(parent, j) && cost[i][j] < min) {
min = cost[i][j];
u = i;
v = j;
}
}

}

if (u != -1 && v != -1) {
union1(parent, rank, u, v);
printf("Edge %d:(%d, %d) cost:%d\n", edgeCount, u, v, min);
minCost += min;
edgeCount++;
}
}

printf("Minimum cost= %d\n", minCost);
}




int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
