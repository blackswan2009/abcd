#include <stdio.h>
#define INF 99999
#define MAX 100
int main() {
    int n, i, j, k, dist[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    printf("\nShortest distances between every pair of vertices:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf(dist[i][j] == INF ? "INF " : "%3d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
