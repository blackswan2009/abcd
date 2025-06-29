#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int main() {
    int V, E;
    int graph[MAX][MAX];
    int i, j;

    // Initialize the graph
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            graph[i][j] = INT_MAX;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Input each edge
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    // MST_Prim(G, w)
    bool inB[MAX] = {false};  // Represents set B
    inB[0] = true; // Start with vertex 0 (arbitrary)

    int edgesInMST = 0;
    printf("Edges in MST:\n");

    while (edgesInMST < V - 1) {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        // Find (u,v) where u ∈ V - B and v ∈ B with min weight
        for (i = 0; i < V; i++) {
            if (inB[i]) {
                for (j = 0; j < V; j++) {
                    if (!inB[j] && graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        u = j;
                        v = i;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("(%d, %d) weight: %d\n", v, u, minWeight);
            inB[u] = true;
            edgesInMST++;
        } else {
            printf("Graph is not connected. MST not possible.\n");
            break;
        }
    }

    return 0;
}
