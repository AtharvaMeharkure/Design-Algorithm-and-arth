#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N


void floydWarshall(int n, int dist[MAX_N][MAX_N]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printMatrix(int n, int dist[MAX_N][MAX_N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%5s","INF");
            else
                printf("%5d",dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, e;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    printf("Enter the number of edges : ");
    scanf("%d", &e);

    int dist[MAX_N][MAX_N];

    // initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // input edges
    for (int k = 0; k < e; k++) {
        int u, v, w;
        printf("Enter source : ");
        scanf("%d", &u);
        printf("Enter destination : ");
        scanf("%d", &v);
        printf("Enter weight : ");
        scanf("%d", &w);
        dist[ u - 1][ v - 1] = w;  // adjust for 1-based input
    }

    floydWarshall(n, dist);

    printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
    printMatrix (n, dist);

    return 0;
}


//write your code here..
