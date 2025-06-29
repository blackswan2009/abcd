#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int main() {
    int V, E, i, j;
    int graph[MAX][MAX];
    int dist[MAX];
    bool visited[MAX] = {false};

    // Input graph
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        // Remove next line if graph is directed
        graph[v][u] = w;
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialization
    for (i = 0; i < V; i++) {
        dist[i] = graph[source][i];
    }
    dist[source] = 0;
    visited[source] = true;

    // Dijkstra's algorithm
    for (int count = 1; count < V; count++) {
        int minDist = INF;
        int y = -1;

        // Find the node y in V - S with the minimum distance
        for (i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                y = i;
            }
        }

        if (y == -1) {
            // Remaining nodes are unreachable
            break;
        }

        visited[y] = true;

        // Relaxation step
        for (j = 0; j < V; j++) {
            if (!visited[j] && graph[y][j] != INF && dist[y] + graph[y][j] < dist[j]) {
                dist[j] = dist[y] + graph[y][j];
            }
        }
    }

    // Output shortest distances
    printf("Shortest distances from vertex %d:\n", source);
    for (i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}
