#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX];     // 0 = WHITE, 1 = GRAY, 2 = BLACK
int p[MAX];         // Parent array
int pre[MAX];       // Discovery time
int post[MAX];      // Finishing time
int time = 0;

int adj[MAX][MAX];  // Adjacency matrix
int n;              // Number of vertices

// Function to perform DFS_VISIT(u)
void DFS_VISIT(int u) {
    color[u] = GRAY;
    time = time + 1;
    pre[u] = time;

    for (int v = 0; v < n; v++) {
        if (adj[u][v] && color[v] == WHITE) {
            p[v] = u;
            DFS_VISIT(v);
        }
    }

    color[u] = BLACK;
    time = time + 1;
    post[u] = time;
}

// Function to perform DFS(G)
void DFS() {
    for (int u = 0; u < n; u++) {
        color[u] = WHITE;
        p[u] = -1; // NIL
    }

    time = 0;

    for (int u = 0; u < n; u++) {
        if (color[u] == WHITE) {
            DFS_VISIT(u);
        }
    }
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    memset(adj, 0, sizeof(adj));

    printf("Enter %d edges (u v) where u and v are vertex indices [0 to %d]:\n", edges, n-1);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed graph
        // For undirected graph, add: adj[v][u] = 1;
    }

    DFS();

    // Output discovery and finishing times
    printf("\nVertex | Discovery | Finishing | Parent\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("  %2d   |    %2d     |    %2d     |  %2d\n", i, pre[i], post[i], p[i]);
    }

    return 0;
}

